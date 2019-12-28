#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H
#include <string>
//using namespace std;
/*
Command Interface
*/
class Compiler;
class Command {

public:
	//the args that execute gets depends on you- I need compiler as arg
	virtual int execute(Compiler cp,std::string s);
	//virtual ~Command() = 0;
};
#endif


