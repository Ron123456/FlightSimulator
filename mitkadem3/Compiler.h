#ifndef PROJECT_COMPILER_H
#define PROJECT_COMPILER_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
/**
 * Compiler Interface
 */
class Compiler {
	void parser(string[]);
	//copy constructor of fstream is not allowed so I used by refrence
	string* lexer(fstream& f);
public:
	void read(fstream& f);
	Compiler() {};
	
};
#endif
