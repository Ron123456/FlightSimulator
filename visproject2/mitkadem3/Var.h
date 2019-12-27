#include <string>
using namespace std;
class Var {
	float value;
	string location;
	bool updateFromSim;
public:
	Var(string loc,bool update) :location(loc), updateFromSim(update) {};
	void setVal(float val) { value = val; };
	float getVal() { return this->value; };
};