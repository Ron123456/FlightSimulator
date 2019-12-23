#include "Compiler.h"
#include <algorithm>
Compiler:: Compiler() {
	//add names to command map
}
//the main method of compiler
void Compiler::read(fstream& f) {

	vector<string> tokens = lexer(f);
	cout << "lexer finished" << endl;
	for (int i = 0; i < tokens.size(); i++) {
		cout << tokens[i] << ",";
	}
	cout << endl;
	//run the actual program
	this->parser(tokens);
	std::cout << "compiler finshed" << endl;
}
//a new substr better suited for our needs
string newsubstr(string s, size_t start_index, size_t end_index) {
	return s.substr(start_index, end_index - start_index + 1);
}

void conditionLexer(string line, vector<string> &tokens, vector<string> operands) {
	//check for each operator if it exists
	for (int i = 0; i < operands.size(); i++) {
		//if the operand exists,
		if (line.find(operands[i]) != string::npos) {
			//push the var name
			tokens.push_back(line.substr(0,line.find(operands[i])));
			//push operand
			tokens.push_back(operands[i]);
			//push the other operator
			tokens.push_back(newsubstr(line,line.find(operands[i])+operands[i].length(),line.find("{")-1));
			//push {
			tokens.push_back("{");
			//we found the operator and can stop
			break;
		}
	}
	cout << "no legal op FOUND\n";
}

bool isCommandWithArgs(string s) {
	if (s.rfind("Print", 0) == 0 || s.rfind("openDataServer", 0) == 0 || s.rfind("connectControlClient", 0) == 0
		|| s.rfind("Sleep", 0) == 0) {
		return true;
	}
	return false;
}

//breaks down the stream to tokens. TODO- the code can be refactored & improved, if we have time I'll do
vector<string> Compiler::lexer(fstream& f) {
	string line;
	// Declaring Vector of String type 
	vector<string> tokens;
	while (!f.eof()) {
		std::getline(f, line);
		//erase tabs first of all
		line.erase(remove(line.begin(), line.end(), '\t'),line.end());
		//dont erase spaces in print command
		if (line.rfind("Print", 0) == 0 ) {
			tokens.push_back("Print");
			line = line.substr(line.find("("));
			//push (
			tokens.push_back("(");
			//push inside
			tokens.push_back(line.substr(1, line.find(")")-1));
			tokens.push_back(")");
		}
		//handle if and while
		else if(line.rfind("while", 0) == 0 || line.rfind("if", 0) == 0){
			//push the if/while
			tokens.push_back(line.substr(0,line.find(' ')));
			//cut the 'while '
			line = line.substr(line.find(' '));
			//handle =< => == < > and such. insert the { and }
			//delete spaces
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
			//IT MATTERS which operator to check first
			vector<string> operands{ "==","<=",">=","<",">","!=" };
			conditionLexer(line,tokens,operands);
			//divide to all operators
		}
		else {
			//if it's Command(arg1,arg2,...,argN) we can remove the first ( and last )
			if (isCommandWithArgs(line)) {
				//you can sperate the the () from the argument- expressions won't be destroyed
				if (line.find('(') != string::npos) {
					int index = line.find("(");
					//insert the 'Command' to the vector
					tokens.push_back(line.substr(0,index));
					//insert (
					tokens.push_back("(");
					int found = index;
					//insert all of the arguments- until ...,argN)
					while (line.find(',',found+1) != string::npos) {
						//push 'arg1'
						tokens.push_back(newsubstr(line,found + 1, line.find(',', found + 1)-1));
						//find the next ,
						found = line.find(',', found + 1);
					}
					//when finished, we need to deal with argN
					if (line.find(')', found + 1) != string::npos) {
						//push argN
						tokens.push_back(newsubstr(line,found + 1, line.find(')', found + 1)-1));
						//push )
						tokens.push_back(")");
					}
					else {
						throw "invalid text! no ')' found";
					}
				}
				else {
					throw "invalid text! no '(' found";
				}
			}
			//if it's a var initialization or value assgiment with initialization- need to deal with no spaces maybe
			else if (line.rfind("var", 0)==0) {
				//push 'var'
				tokens.push_back(line.substr(0, 3));
				//cut the 'var '
				line = line.substr(4, line.length() - 2);
				//if it's assigment =
				if (line.find('=') != string::npos) {
					//push the name of var- either until '=' or until ' '
					//if the = appears before, it's var x=8349+23
					if (line.find('=') < line.find(' ')) {
						//push the 'x'
						tokens.push_back(line.substr(0, line.find('=')));
						//push '='
						tokens.push_back("=");
						//push the expression
						string temp = line.substr(line.find('=') + 1);
						//if it's = 8349+23
						if (line[line.find('=') + 1] == ' ') {
							
							//there can be multiple spaces- O_o	
							tokens.push_back(temp.substr(temp.find_first_not_of(' ')));
						}
						//else, it's =8349+23
						else {
							tokens.push_back(temp);
						}
						
					}
					//else, it's var x =87458237+3 or var x = 87458237+3
					else {
						//push the 'x'
						tokens.push_back(line.substr(0, line.find(' ')));
						//push '='
						tokens.push_back("=");
						//push the expression
						string temp = line.substr(line.find('=') + 1);
						//if it's = 8349+23
						if (line[line.find('=') + 1] == ' ') {
							//there can be multiple spaces- O_o	
							tokens.push_back(temp.substr(temp.find_first_not_of(' ')));
						}
						//else, it's =8349+23
						else {
							tokens.push_back(line.substr(line.find('=') + 1));
						}
					}
				}
				//else, it's -> type
				else if(line.find("->") != string::npos){
					//if the = appears before, it's var x->sim(..)
					if (line.find("->") < line.find(' ')) {
						//push the 'x'
						tokens.push_back(line.substr(0, line.find("->")));
						//push '->'
						tokens.push_back("->");
						//push the  sim
						//string temp = line.substr(line.find('->') + 1);
						//line is not 'sim(...)' we skipped any spaces
						line = line.substr(line.find("sim"));
						//push 'sim('
						tokens.push_back("sim");
						tokens.push_back("(");
						size_t findbrac = line.find('(');
						//push asd/simulator/....
						tokens.push_back(newsubstr(line, findbrac + 1, line.find(')', findbrac + 1) - 1));
						//push )
						tokens.push_back(")");
					}
					//TODO- merge into one option
					//else, it's var x ->sim(...)
					else {
						//push the 'x'
						tokens.push_back(line.substr(0, line.find(' ')));
						//push '->'
						tokens.push_back("->");
						line = line.substr(line.find("sim"));
						//push 'sim('
						tokens.push_back("sim");
						tokens.push_back("(");
						size_t findbrac = line.find('(');
						//push asd/simulator/....
						tokens.push_back(newsubstr(line, findbrac + 1, line.find(')', findbrac + 1) - 1));
						//push )
						tokens.push_back(")");

					}
				}
				//<- type we can assume code is correct
				else {
					//remove spaces
					line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
					//push var name
					tokens.push_back(line.substr(0, line.find("<-")));
					tokens.push_back("<-");
					line = line.substr(line.find("sim"));
					//push 'sim('
					tokens.push_back("sim");
					tokens.push_back("(");
					size_t findbrac = line.find('(');
					//push asd/simulator/....
					tokens.push_back(newsubstr(line, findbrac + 1, line.find(')', findbrac + 1) - 1));
					//push )
					tokens.push_back(")");
				}
			}
			//else, it's a var value assgiment fd= 4
			else if(line.find('=') != string::npos){
				//remove spaces
				line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
				//get the 'varname' part
				string temp = line.substr(0,line.find('='));
				tokens.push_back(temp.substr(0,temp.find(' ')));
				//push '='
				tokens.push_back("=");
				temp= line.substr(line.find('=') + 1);
				//push the val
				tokens.push_back(temp);

			}
			//if it's } just push
			else if(line.compare("}")==0){
				tokens.push_back(line);
			}
			//functions
			else {

			
			}
		}
	}
	return tokens;
}

