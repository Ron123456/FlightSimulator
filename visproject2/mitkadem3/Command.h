
#include <string>
using namespace std;
/*
Command Interface
*/
class Command {

public:
	//the args that execute gets depends on you
	virtual int execute(std::string s);

};


