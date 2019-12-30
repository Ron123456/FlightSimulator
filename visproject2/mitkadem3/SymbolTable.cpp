#include <string>
#include "SymbolTable.h"
//TODO- add the changes to a queue that will execute
void SymbolTable::createVar(string name, string path, bool connc) {
	//default value of a var is 0
	Var* v = new Var(path,connc);
	this->var_names.insert({ name,v });
	this->paths.insert({ path,v });
}
void SymbolTable::setValueFromName(string name, float val) {
	this->var_names.find(name)->second->setVal(val);
	//this line requires the default constructor which we don't have5
	//this->var_names[name].setVal(val);
}
void SymbolTable::setValueFromPath(string path, float val) {
	this->paths.find(path)->second->setVal(val);

	/*std::cout << "updating " << path << "with val " << val;
	for (auto it = paths.begin(); it != paths.end(); it++)
	{
		std::cout << it->first  // path (key)
			<< ':'
			<< std::to_string(it->second->getVal())   // string's value 
			<< std::endl;
	}*/
	//this line below requires the default constructor which we don't have5
	//this->paths[path].setVal(val);
}
float SymbolTable::get(string varname) {
	return this->var_names.find(varname)->second->getVal();
	//this line below requires the default constructor which we don't have5
	//return this->var_names[varname].getVal();
}
bool SymbolTable::containsPathToUpdate(string path) {
	return this->paths.find(path) != this->paths.end() && this->paths.find(path)->second->getConnc();
}