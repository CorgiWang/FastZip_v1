#ifndef FASTX_H
#define FASTX_H

#include "FastZip.h"
#include "DescCluster.h"
#include "SeqCluster.h"
#include "BioCluster.h"
#include "QualCluster.h"

class FastX {
public:
	static U1 Th;
	static U2 W;
	static U4 H;

	DescCluster descClus[2];
	BioCluster bioClus;
	QualCluster qualClus;

	Cluster * clus[4];

	FastX() {
		clus[0] = &descClus[0];
		clus[1] = &bioClus;
		clus[2] = &descClus[1];
		clus[3] = &qualClus;
	}

	void tin_File(ifstream&);
	void tout_File(ofstream&);

	void bin_File(ifstream&);
	void bout_File(ofstream&);

	void encode_File();
	void decode_File();
};



#endif /* FASTX_H */

