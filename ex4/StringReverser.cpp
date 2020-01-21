#include "StringReverser.h"
std::string StringReverser::solve(std::string p) {
	int n = p.length();
	std::string str(n, ' ');
	for (int i = 0; i < n ; i++) {
		str[i] = p[n - 1 - i];
	}
	return str;
}