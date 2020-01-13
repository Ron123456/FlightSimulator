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
 * Compiler class- the main class that controls all of the program
 */
class Compiler {
	//a symbol table that handles the compiler's variables
	SymbolTable* sym;
	//a mapping between names and commands
	unordered_map<string, Command> commands;
	//the lexer method
	void lexer(ifstream& f);
public:
	//a class that handles our connection as a client
    Connection connection;
    Parser* parser = new Parser();
	//the token that lexer returns and we iterate over it
    vector<string> token;
	//index tells us where are we in the vector
    int index = 0;
	void read(ifstream& f);
	bool closeConnection=false;
    Compiler();

    SymbolTable* getSymbolTable() { return this->sym; };
};
#endif
