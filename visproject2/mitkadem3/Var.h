#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H
#include <string>
using namespace std;
class Var {
	float value;
	string location;
	//if connc=1 then it means the sim will update us ,if connc=0 then we update sim/just change val
	bool updateFromSim;
public:
	//a constrcutor for updatedvars
	Var(string loc, bool update) :location(loc), updateFromSim(update) { this->value = 0; };
	//constructor for normal vars
	Var(float val) :value(val) { this->location = ""; this->updateFromSim = 0; };
	void setVal(float val) { this->value = val; };
	float getVal() { return this->value; };
	bool getConnc() { return this->updateFromSim; };
};
#endif