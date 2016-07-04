#include "FastX.h"

U1 FastX::Th = 0;
U2 FastX::W = 0;
U4 FastX::H = 0;

void FastX::tin_File(ifstream& ifs) {
	Stamp(__func__, 0);

	vector<string> seg[4];
	string ts;
	U1 sn = 0;

	getline(ifs, ts);
	seg[sn++].resize(1, ts);
	Th = ('@' == ts[0] ? 4 : 2);

	getline(ifs, ts);
	seg[sn++].resize(1, ts);
	W = ts.length();

	if (4 == Th) {
		getline(ifs, ts);
		seg[sn++].resize(1, ts);
		getline(ifs, ts);
		seg[sn++].resize(1, ts);
	}

	while (!ifs.eof()) {
		sn &= ~Th;
		getline(ifs, ts);
		seg[sn++].push_back(ts);
	}
	H = seg[1].size();
	just = (seg[0].size() == H);
	if (!just) {
		seg[0].resize(H);
	}

	for (U1 i = 0; i < Th; i++) {
		clus[i]->tin_Cluster(seg[i]);
	}

	Stamp(__func__, 1);
}

void FastX::tout_File(ofstream& ofs) {
	Stamp(__func__, 0);

	vector<string> seg[4];

	for (U1 i = 0; i < Th; i++) {
		clus[i]->tout_Cluster(seg[i]);
	}

	ofs << seg[0][0];
	for (U1 i = 1; i < Th; i++) {
		ofs << endl << seg[i][0];
	}
	for (U4 i = 1; i < H; i++) {
		for (U1 j = 0; j < Th; j++) {
			ofs << endl << seg[j][i];
		}
	}
	if (!just) {
		ofs << endl;
	}

	Stamp(__func__, 1);
}

void FastX::bin_File(ifstream& ifs) {
	Stamp(__func__, 0);

	ifs.read((char*) &Th, sizeof (Th));
	ifs.read((char*) &W, sizeof (W));
	ifs.read((char*) &H, sizeof (H));
	ifs.read((char*) &just, sizeof (just));
	for (U1 i = 0; i < Th; i++) {
		clus[i]->bin_Cluster(ifs);
	}

	Stamp(__func__, 1);
}

void FastX::bout_File(ofstream& ofs) {
	Stamp(__func__, 0);

	ofs.write((char*) &Th, sizeof (Th));
	ofs.write((char*) &W, sizeof (W));
	ofs.write((char*) &H, sizeof (H));
	ofs.write((char*) &just, sizeof (just));
	for (U1 i = 0; i < Th; i++) {
		clus[i]->bout_Cluster(ofs);
	}

	Stamp(__func__, 1);
}

void FastX::encode_File() {
	Stamp(__func__, 0);

	for (U1 i = 0; i < Th; i++) {
		clus[i]->encode_Cluster();
	}

	Stamp(__func__, 1);
}

void FastX::decode_File() {
	Stamp(__func__, 0);

	for (U1 i = 0; i < Th; i++) {
		clus[i]->decode_Cluster();
	}

	Stamp(__func__, 1);
}
