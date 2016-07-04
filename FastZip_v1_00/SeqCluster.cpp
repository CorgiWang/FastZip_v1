#include "SeqCluster.h"
#include "FastX.h"

void SeqCluster::tin_Cluster(vector<string>& seg) {
	Stamp(__func__, 0);

	NoS = 1;
	strips.resize(1, Strip());
	strips[0].ori.reserve(FastX::H * FastX::W);
	string& ori = strips[0].ori;
	for (U4 i = 0; i < FastX::H; i++) {
		ori.append(seg[i]);
	}

	Stamp(__func__, 1);
}

void SeqCluster::tout_Cluster(vector<string>& seg) {
	Stamp(__func__, 0);

	seg.resize(FastX::H, string());
	string& ori = strips[0].ori;
	U8 len = ori.length();
	U4 ct = 0;
	for (U8 i = 0; i < len; i += FastX::W) {
		seg[ct++] = ori.substr(i, FastX::W);
	}

	Stamp(__func__, 1);
}
