#include "Compiler.h"
#include <algorithm>
#include "openServerCommand.h"
#include <chrono>
/*Compiler::Compiler() {
	parser1 = new Parser();
}*/
//the main method of compiler
void Compiler::read(ifstream& f) {

	//run the lexer, updates the 'token' field of compiler
    lexer(f);
	//run the parser, until the end of 'token' vector
    while (this->index < token.size()) {
        this->parser->parsing(this);
    }
    //tell the other threads to close
	this->closeConnection = true;
	//close the client
	this->connection.closeconnection();
}
//a new substr better suited for our needs
string newsubstr(string s, size_t start_index, size_t end_index) {
    return s.substr(start_index, end_index - start_index + 1);
}

//a function used in lexing while and if
void conditionLexer(string line, vector<string> &tokens, vector<string> operands) {
    //check for each operator if it exists
    for (int i = 0; (unsigned int)i < operands.size(); i++) {
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
}

bool isCommandWithArgs(string s) {
    if (s.rfind("Print", 0) == 0 || s.rfind("openDataServer", 0) == 0 || s.rfind("connectControlClient", 0) == 0
        || s.rfind("Sleep", 0) == 0) {
        return true;
    }
    return false;
}

//breaks down the stream to tokens.
void Compiler::lexer(ifstream& f) {
    string line;
    // Declaring Vector of String type
    vector<string> tokens;
    int lineno = 0;
	//go over the lines in the file
    while (!f.eof()) {
        std::getline(f, line);
		//check if it's an empty line
		if (line.size() == 0) {
			//cout << "got it"<<endl;
			std::getline(f, line);
			continue;
		}
			
		//between windows and unix
		if (line[line.size() - 1] == '\r') {
			//cout << "removed r " << lineno<<endl;
			line = line.substr(0, line.size() - 1);
		}
        lineno++;
        //erase ALL tabs first of all
        line.erase(remove(line.begin(), line.end(), '\t'), line.end());
        //remove front spaces
        line=line.substr(line.find_first_not_of(" "), string::npos);
        //dont erase spaces in print command
        if (line.rfind("Print", 0) == 0 ) {
            tokens.push_back("Print");
            line = line.substr(line.find("("));
            //push what's inside Print
            tokens.push_back(line.substr(1, line.find(")")-1));
        }
          //handle if and while
        else if(line.rfind("while", 0) == 0 || line.rfind("if", 0) == 0){
            //push the if/while
            tokens.push_back(line.substr(0,line.find(' ')));
            //cut the 'while '
            line = line.substr(line.find(' '));
            //delete spaces
            std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
            line.erase(end_pos, line.end());
			//handle  =< => == < > and such. and insert the { and }
            //IT MATTERS which operator to check first
            vector<string> operands{ "==","<=",">=","<",">","!=" };
			//handles each operator
			conditionLexer(line,tokens,operands);
        }
        else {
            //if it's Command(arg1,arg2,...,argN) we can remove the first ( and last )
            if (isCommandWithArgs(line)) {
                //you can sperate the the () from the argument- expressions won't be destroyed
                if (line.find('(') != string::npos) {
					int index = line.find("(");
                    //insert the 'Command' to the vector
                    tokens.push_back(line.substr(0,index));
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
                        //if line is not 'sim(...)' -we skipped any spaces
                        line = line.substr(line.find("sim"));
                        //push 'sim'
                        tokens.push_back("sim");
                        size_t findbrac = line.find('(');
                        //push asd/simulator/....
                        tokens.push_back(newsubstr(line, findbrac + 1, line.find(')', findbrac + 1) - 1));
                    }
                        //else, it's var x ->sim(...)
                    else {
                        //push the 'x'
                        tokens.push_back(line.substr(0, line.find(' ')));
                        //push '->'
                        tokens.push_back("->");
                        line = line.substr(line.find("sim"));
                        //push 'sim'
                        tokens.push_back("sim");
                        size_t findbrac = line.find('(');
                        //push asd/simulator/....
                        tokens.push_back(newsubstr(line, findbrac + 1, line.find(')', findbrac + 1) - 1));

                    }
                }
                    //<- type we can assume code is correct
                else {
                    //remove spaces
                    //	line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
                    std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
                    line.erase(end_pos, line.end());
                    //push var name
                    tokens.push_back(line.substr(0, line.find("<-")));
                    tokens.push_back("<-");
                    line = line.substr(line.find("sim"));
                    //push 'sim'
                    tokens.push_back("sim");
                    size_t findbrac = line.find('(');
                    //push asd/simulator/....
                    tokens.push_back(newsubstr(line, findbrac + 1, line.find(')', findbrac + 1) - 1));
                }
            }
               //else, it's a var value assgiment x= 4
            else if(line.find('=') != string::npos){
                //remove spaces
                //line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
                std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
                line.erase(end_pos, line.end());
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
                //else it's functions- such as takeoff(var x){
			//we have decided to not support functions
            else {
                //push the 'takeoff'
                if (line.find('(') != string::npos) {
                    tokens.push_back(line.substr(0, line.find('(')));
                    //cut the line- 'var x){'
                    line = line.substr(line.find("(") + 1, string::npos);
                    //check if definition or usage
                    if (line.find("var") != string::npos) {
                        tokens.push_back("var");

                        line = line.substr(line.find("var") + 4, string::npos);
                        //line= x){
                        tokens.push_back(line.substr(0, line.find(")")));
                        //tokens.push_back(")");
                        tokens.push_back("{");
                    }
                        //else it's usage- takeoff(500)
                    else {
                        tokens.push_back(line.substr(0, line.find(")")));
                    }
                }
            }
        }
    }
    token = tokens;
}

Compiler::Compiler() {
    parser = new Parser();
    this->sym = new SymbolTable();
    parser->createmap();
}
