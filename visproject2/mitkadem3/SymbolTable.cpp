#include <string>
#include "SymbolTable.h"
//TODO- add the changes to a queue that will execute
void SymbolTable::createVar(string name, string path, bool connc) {
	Var v(path,connc);
	this->var_names.insert({ name,v });
	this->paths.insert({ path,v });
}
void SymbolTable::setValueFromName(string name, float val) {
	this->var_names.find(name)->second.setVal(val);
	//this line requires the default constructor which we don't have5
	//this->var_names[name].setVal(val);
}
void SymbolTable::setValueFromPath(string path, float val) {
	this->paths.find(path)->second.setVal(val);
	//this line below requires the default constructor which we don't have5
	//this->paths[path].setVal(val);
}
float SymbolTable::get(string varname) {
	return this->var_names.find(varname)->second.getVal();
	//this line below requires the default constructor which we don't have5
	//return this->var_names[varname].getVal();
}
bool SymbolTable::containsPathToUpdate(string path) {
	return this->paths.find(path) != this->paths.end() && this->paths.find(path)->second.getConnc();
}