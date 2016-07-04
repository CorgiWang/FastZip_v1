#include "FastZip.h"
#include "FastX.h"

string arg[4];
bool zipping;

void warn(U1 id) {
	if (0 == id)
		cout << "参数 数量错误!!!" << endl;
	else
		cout << "参数 格式错误 - #" << U2(id) << endl;
}

bool UI(int argc, char** argv) {
	bool ok = true;

	for (U1 i = 0; i < argc; i++) {
		arg[i] = argv[i];
	}

	if (4 == argc) {
		if (arg[1] == "-E") {
			zipping = true;
		} else if (arg[1] == "-D") {
			zipping = false;
		} else {
			warn(1);
			ok = false;
		}
	} else {
		warn(0);
		ok = false;
	}

	return ok;
}

int main(int argc, char** argv) {
	Stamp(__func__, 0);

	FastX fx;

	if (UI(argc, argv)) {
		if (zipping) {
			ifstream ifs(arg[2].c_str());
			fx.tin_File(ifs);
			ifs.close();
			fx.encode_File();
			ofstream ofs(arg[3].c_str(), ios::binary);
			fx.bout_File(ofs);
			ofs.close();
		} else {
			ifstream ifs(arg[2].c_str(), ios::binary);
			fx.bin_File(ifs);
			ifs.close();
			fx.decode_File();
			ofstream ofs(arg[3].c_str());
			fx.tout_File(ofs);
			ofs.close();
		}
	}

	Stamp(__func__, 1);

	return 0;
}

