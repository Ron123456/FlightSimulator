
#include <string>

using namespace std;
/*
Command Interface
*/
class Command {

public:
	//the args that execute gets depends on you- I need compiler as arg
	virtual int execute(Compiler cp,std::string s);

};


