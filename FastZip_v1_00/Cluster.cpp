#include "Cluster.h"

void Cluster::bin_Cluster(ifstream& ifs) {
	Stamp(__func__, 0);
	
	ifs.read((char*) &NoS, 1);
	strips.resize(NoS);
	for (U1 i = 0; i < NoS; i++) {
		strips[i].bin_Strip(ifs);
	}
	
	Stamp(__func__, 1);
}

void Cluster::bout_Cluster(ofstream& ofs) {
	Stamp(__func__, 0);
	
	ofs.write((char*) &NoS, 1);
	for (U1 i = 0; i < NoS; i++) {
		strips[i].bout_Strip(ofs);
	}
	
	Stamp(__func__, 1);
}

void Cluster::encode_Cluster() {
	Stamp(__func__, 0);
	
	for (U1 i = 0; i < NoS; i++) {
		strips[i].encode_Strip();
	}
	
	Stamp(__func__, 1);
}

void Cluster::decode_Cluster() {
	Stamp(__func__, 0);
	
	for (U1 i = 0; i < NoS; i++) {
		strips[i].decode_Strip();
	}
	
	Stamp(__func__, 1);
}

