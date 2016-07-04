#ifndef SEQCLUSTER_H
#define SEQCLUSTER_H

#include "Cluster.h"

class SeqCluster : public Cluster {
public:

	virtual void tin_Cluster(vector<string>&);
	virtual void tout_Cluster(vector<string>&);
};

#endif /* SEQCLUSTER_H */

