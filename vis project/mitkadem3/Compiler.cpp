#include "Compiler.h"
#include <algorithm>
#include <vector>
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
	string line;
	// Declaring Vector of String type 
	vector<string> colour;
	while (!f.eof()) {
		std::getline(f, line);
		//erase tabs first of all
		line.erase(remove(line.begin(), line.end(), '\t'),line.end());
		//dont erase spaces in print command
		if (!line.rfind("Print", 0) == 0 ) {
			
		}
		else if(!line.rfind("while", 0) == 0){

		}
		else {
			line.
		}
	}
}