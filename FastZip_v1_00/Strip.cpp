#include "Strip.h"

void Strip::encode_Strip() {
//	Stamp(__func__, 0);

	Dict* dict = new Dict();
	ori.push_back(MIN_LET + NoL);
	U8 len = ori.length();

	code.resize(4, 0);
	U8 realSize = 0;

	U4 mask = 0xFFFFFF00;
	U1 level = 1;
	U4 ct = 0;

	for (U8 i = 0; i < len; i++) {
		U4 cd = dict->scan(ori[i]);
		if (NoL != cd) {
			if (cd & mask) {
				pushCode(realSize, NoL, level);
				mask <<= 8;
				level++;
			}
			pushCode(realSize, cd, level);
			if (LIM == ++ct) {
				delete dict;
				dict = new Dict();
				dict->scan(ori[i]);
				ct = 0;
			}
		}
	}

	code.resize(realSize);
	ori.resize(ori.size() - 1);

	delete dict;

//	Stamp(__func__, 1);
}

void Strip::decode_Strip() {
//	Stamp(__func__, 0);

	Dict* dict = new Dict();
	ori.clear();

	U4 mask = 0x000000FF;
	U1 level = 1;
	U8 sz = code.size();
	U8 pos = 0;
	U4 ct = 0;

	while (pos < sz) {
		U4 idx = *((U4*) (code.data() + pos)) & mask;
		pos += level;

		if (NoL == idx) {
			mask <<= 8;
			mask |= 0xFF;
			level++;
		} else {
			string word;
			if (dict->book.size() == idx) {
				U4 len;
				U4 i = 0;

				dict->lookUp(word, dict->curr);
				len = word.length();
				for (; i < len; i++) {
					dict->scan(word[i]);
				}

				dict->lookUp(word, idx, len);
				len = word.length();
				for (; i < len; i++) {
					dict->scan(word[i]);
				}
			} else {
				dict->lookUp(word, idx);
				U4 len = word.length();
				for (U4 i = 0; i < len; i++) {
					dict->scan(word[i]);
				}
			}
			ori.append(word);
			if (LIM == ++ct) {
				delete dict;
				dict = new Dict();
				ct = 0;
			}
		}
	}
	delete dict;

//	Stamp(__func__, 1);
}

void Strip::bin_Strip(ifstream& ifs) {
	//	Stamp(__func__, 0);

	U8 sz;
	ifs.read((char*) (&sz), 8);
	code.resize(sz);
	ifs.read((char*) code.data(), sz);

	//	Stamp(__func__, 1);
}

void Strip::bout_Strip(ofstream& ofs) {
	//	Stamp(__func__, 0);

	U8 sz = code.size();
	ofs.write((char*) (&sz), 8);
	ofs.write((char*) code.data(), sz);

	//	Stamp(__func__, 1);
}

void Strip::showCode() {

	cout << endl;
	U4 sz = code.size();
	for (U4 i = 0; i < sz; i++) {
		cout << '\t' << U2(code[i]);
	}
	cout << endl;

}
