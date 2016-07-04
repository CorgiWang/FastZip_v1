#ifndef DESCCLUSTER_H
#define DESCCLUSTER_H

#include "Cluster.h"

class DescCluster : public Cluster {
public:
	
	string getPattern(string& line);

	virtual void tin_Cluster(vector<string>&);
	virtual void tout_Cluster(vector<string>&);

};



#endif /* DESCCLUSTER_H */

