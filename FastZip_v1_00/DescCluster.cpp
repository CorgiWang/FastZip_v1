#include "DescCluster.h"
#include "FastX.h"

string DescCluster::getPattern(string& line) {
	Stamp(__func__, 0);

	string patt;
	U2 len = line.length();
	for (U2 i = 0; i < len; i++) {
		if (IsSymbol(line[i]))
			patt.push_back(line[i]);
	}

	Stamp(__func__, 1);
	return patt;
}

void DescCluster::tin_Cluster(vector<string>& seg) {
	Stamp(__func__, 0);
	
	string patt = getPattern(seg[0]);
	NoS = patt.length();
	strips.resize(NoS, Strip());
	for (U4 i = 0; i < FastX::H; i++) {
		U2 right = seg[i].length();
		U2 left;
		for (U1 j = NoS - 1; j < NoS; j--) {
			for (left = right - 1; seg[i][left] != patt[j]; left--);
			strips[j].ori.append(seg[i].substr(left, right - left));
			right = left;
		}
	}
	
	Stamp(__func__, 1);
}

void DescCluster::tout_Cluster(vector<string>& seg) {
	Stamp(__func__, 0);
	
	seg.resize(FastX::H, string());

	for (U1 i = 0; i < NoS; i++) {
		string& ori = strips[i].ori;
		U1 sym = ori[0];
		U8 right = ori.length();
		U8 left;
		for (U4 j = FastX::H - 1; j < FastX::H; j--) {
			for (left = right - 1; ori[left] != sym; left--);
			seg[j].append(ori.substr(left, right - left));
			right = left;
		}
	}
	
	Stamp(__func__, 1);
}

