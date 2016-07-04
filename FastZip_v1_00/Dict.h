#ifndef DICT_H
#define DICT_H

#include "FastZip.h"

const U1 MIN_LET = '\0';
const U1 MAX_LET = '~';
const U1 NoL = MAX_LET - MIN_LET + 1;

struct Node {
	U4 depth;
	U1 letter;
	U4 prev;
	vector<U4> next;

	Node(U4 dep = 0, U1 let = NoL, U4 pre = NoL) {
		depth = dep;
		letter = let;
		prev = pre;
		next.resize(NoL + 1, NoL);
	}
};

class Dict {
public:

	vector<Node> book;
	U4 curr;

	Dict() {
		book.reserve(0x10000);
		book.resize(NoL + 1, Node(1));
		for (U2 i = 0; i < NoL; i++) {
			book[i].letter = i;
			book[NoL].next[i] = i;
		}
		book[NoL].depth = 0;

		curr = NoL;
	}

	U4 scan(U1);
	void lookUp(string&, U4, U4 has = 0);


};


#endif /* DICT_H */

