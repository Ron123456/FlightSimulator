#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H
#include <string>
using namespace std;
class Var {
	float value;
	string location;
	bool updateFromSim;
public:
	Var(string loc, bool update) :location(loc), updateFromSim(update) { this->value = 0; };
	void setVal(float val) { value = val; };
	float getVal() { return this->value; };
	bool getConnc() { return this->updateFromSim; };
};
#endif