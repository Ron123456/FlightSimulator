#include "Compiler.h"
//the main method of compiler
void Compiler::read(fstream& f) {
	
	string* tokens = lexer(f);
	//run the actual program
	this->parser(tokens);
	//break down the stream to lines, each line erase the spaces,
	//unless it's a Print command (so we could print with spaces)
	std::cout << "compiler finshed" << endl;
}
//breaks down the stream to tokens
string* Compiler::lexer(fstream& f) {
	//break down the stream to lines, each line ERASE the spaces,
	//unless it's a Print command (so we could print with spaces)
}