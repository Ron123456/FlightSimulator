#ifndef PROJECT_COMPILER_H
#define PROJECT_COMPILER_H
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map> 
#include <vector>
#include "Command.h"
#include "SymbolTable.h"
#include "Parser.h"
#include "Connection.h"
using namespace std;
/**
 * Compiler Interface
 */
class Compiler {
	//later for scopes of FUNCTIONS- we'll do a list of symbol table for each scope
	SymbolTable sym;
	//the thing for parser- that's for you amitush
	unordered_map<string, Command> commands;



	//void parser(vector<string> tokens);
	//copy constructor of fstream is not allowed so I used by refrence
	void lexer(fstream& f);
public:
    Connection connection;
    Parser* parser = new Parser();
    vector<string> token;
    int index = 0;
	void read(fstream& f);

    Compiler();

    SymbolTable getSymbolTable() { return this->sym; };
};
#endif
