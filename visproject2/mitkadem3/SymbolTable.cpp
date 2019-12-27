#include <string>
#include "SymbolTable.h"
//TODO- add the changes to a queue that will execute
void SymbolTable::createVar(string name, string path, bool connc) {
	Var v(path,connc);
	this->var_names.insert({ name,v });
	this->paths.insert({ path,v });
}
void SymbolTable::setValueFromName(string name, float val) {
	this->var_names[name].setVal(val);
}
void SymbolTable::setValueFromPath(string path, float val) {
	this->paths[path].setVal(val);
}
float SymbolTable::get(string varname) {
	return this->var_names[varname].getVal();
}
bool SymbolTable::containsPath(string path) {
	return this->paths.find(path) != this->paths.end();
}