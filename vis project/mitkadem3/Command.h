
#include <string>
using namespace std;
/*
Command Interface
*/
class Command {

public:
	virtual int execute(std::string s)=0;

};


