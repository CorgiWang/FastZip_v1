#ifndef CLUSTER_H
#define CLUSTER_H


#include "FastZip.h"
#include "Strip.h"

class Cluster {
public:

	U1 NoS;
	vector<Strip> strips;

	virtual void tin_Cluster(vector<string>&) = 0;
	virtual void tout_Cluster(vector<string>&) = 0;

	void bin_Cluster(ifstream&);
	void bout_Cluster(ofstream&);

	void encode_Cluster();
	void decode_Cluster();
};



#endif /* CLUSTER_H */

