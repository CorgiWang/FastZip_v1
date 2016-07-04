#include "Dict.h"

U4 Dict::scan(U1 let) {

	U4 ret = NoL;
	U4& nx = book[curr].next[let - MIN_LET];

	if (NoL == nx) {
		ret = curr;
		nx = book.size();
		book.push_back(Node(book[curr].depth + 1, let, curr));
		curr = let - MIN_LET;
	} else {
		curr = nx;
	}

	return ret;
}

void Dict::lookUp(string& wd, U4 idx, U4 has) {
	U4 len = book[idx].depth;
	wd.resize(len);
	for (long i = len - 1; i >= has; i--) {
		wd[i] = book[idx].letter;
		idx = book[idx].prev;
	}
}

