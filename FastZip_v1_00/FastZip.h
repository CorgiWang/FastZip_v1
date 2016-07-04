#ifndef FASTZIP_H
#define FASTZIP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

typedef __uint8_t U1;
typedef __uint16_t U2;
typedef __uint32_t U4;
typedef __uint64_t U8;

const U4 LIM = 0xA00000;

inline bool IsSymbol(char& ch) {
	return !(
			(('0' <= ch)&&(ch <= '9')) ||
			(('A' <= ch)&&(ch <= 'Z')) ||
			(('a' <= ch)&&(ch <= 'z'))
			);
}

inline void Stamp(const char* fn, U1 op) {

	static const U4 T0 = time(NULL);

	const char* s[3] = {
		"Enter",
		"Leave",
		"Running",
	};
	static U2 depth = 0;
	U2 cur = depth;
	switch (op) {
		case 0:
			depth++;
			cur++;
			break;
		case 1:
			depth--;
			break;
	}
	for (U2 i = 1; i < cur; i++) {
		printf("    ");
	}
	printf("%6ld: [%s] %s\n", time(NULL) - T0, fn, s[op]);
}



#endif /* FASTZIP_H */

