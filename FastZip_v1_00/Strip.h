#ifndef STRIP_H
#define STRIP_H

#include "FastZip.h"
#include "Dict.h"

class Strip {
public:

	string ori;
	vector<U1> code;

	inline void pushCode(U8& rs, U4 cd, U1 lv) {
		U4* p = (U4*) (code.data() + rs);
		*p = cd;
		rs += lv;
		code.resize(rs + 4);
	}

	void encodeSection(U8, U8);
	
	void encode_Strip();
	void decode_Strip();

	void bin_Strip(ifstream&);
	void bout_Strip(ofstream&);

	void showCode();

};

#endif /* STRIP_H */

