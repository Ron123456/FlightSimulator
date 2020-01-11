#include <string>
#include "SymbolTable.h"

std::mutex mutex_lock;
//create a var that either updates or gets updated by sim
void SymbolTable::createUpdateVar(string name, string path, bool connc) {
	//default value of a var is 0
	Var* v = new Var(path,connc);
	this->var_names.insert({ name,v });
	this->paths.insert({ path,v });
}
//create a normal var
void SymbolTable::createVar(string name, float val) {
	//default value of a var is 0
	//Var* v = new Var(path, connc);
	Var* v = new Var(val);
	this->var_names.insert({name,v});
}
void SymbolTable::setValueFromName(string name, float val) {
	mutex_lock.lock();
	this->var_names.find(name)->second->setVal(val);
	mutex_lock.unlock();
	//this line requires the default constructor which we don't have5
	//this->var_names[name].setVal(val);
}
//this method will be used only by the openServerCommand
void SymbolTable::setValueFromPath(string path, float val) {
	mutex_lock.lock();
	this->paths.find(path)->second->setVal(val);
	mutex_lock.unlock();
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
string SymbolTable::getPath(string varname) {
	return this->paths.find(varname)->second->getPath();
}
bool SymbolTable::containsPathToUpdate(string path) {
	return this->paths.find(path) != this->paths.end() && (this->paths.find(path)->second->getConnc()==1);
}
void SymbolTable::deleteVar(string varname) {
	mutex_lock.lock();
	//if the var exists
	if (this->var_names.find(varname) != this->var_names.end()) {
		//free the var
		delete (this->var_names.find(varname)->second);
		//delete from the map
		this->var_names.erase(varname);
	}
	else {
		cout << "error in deleting a var!" << endl;
		exit(1);
	}
	mutex_lock.unlock();
}
//check to see if the connc type is 0- which means we need to update the sim as well
bool SymbolTable::isUpdateToSim(string varname) {
	return this->var_names.find(varname) != this->var_names.end() &&
		(this->var_names.find(varname)->second->getConnc() == 0);
}

//in destructor, free the var_names variables as they are both local and updated