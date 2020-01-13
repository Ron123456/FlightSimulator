#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H
#include <string>
//using namespace std;
/*
Command Interface
*/
//forward declaration to prevent circular including
class Compiler;
class Command {

public:
	//the only argument we get is 'Compiler'- it holds everything we need
	virtual int execute(Compiler* cp) { (void)(cp); return 1; };
};
#endif


