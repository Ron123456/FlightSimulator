#include <string>
#include "SymbolTable.h"

std::mutex mutex_lock;
//create a var that either updates or gets updated by sim
void SymbolTable::createUpdateVar(string name, string path, bool connc) {
	//default value of a var is 0
	Var* v = new Var(path,connc);
	//insert to the name-var map
	this->var_names.insert({ name,v });
	//insert to the name-path map
	this->varsToPaths.insert({name,path});
	//insert to the path-name map
	//this will be used when updating vars from the sim
	this->pathsToVars.insert({path,name});
}
//create a normal var, that doesn't update or get updated
void SymbolTable::createVar(string name, float val) {
	//default value of a var is 0
	Var* v = new Var(val);
	//insert it only to the first map- it doesn't have a path
	this->var_names.insert({name,v});
}
//change the value of a variable, based on its name
void SymbolTable::setValueFromName(string name, float val) {
	if (this->var_names.find(name) != this->var_names.end()) {
		//we lock the map, as multiple threads can update the table at the same time
		mutex_lock.lock();
		this->var_names.find(name)->second->setVal(val);
		//unlock the mutex
		mutex_lock.unlock();
	}
}
//this method will be used only by the openServerCommand- setting a var's value based on its path
void SymbolTable::setValueFromPath(string path, float val) {
	//lock the map
	mutex_lock.lock();
	this->var_names.find(pathsToVars.find(path)->second)->second->setVal(val);
	//release the map
	mutex_lock.unlock();
}
//returns the value of a variable
float SymbolTable::get(string varname) {
	return this->var_names.find(varname)->second->getVal();
}
//returns the path of a variable based on its name
string SymbolTable::getPath(string varname) {
	//cout << "getting path" << endl;
	if (this->varsToPaths.find(varname) != this->varsToPaths.end()) {
		return this->varsToPaths.find(varname)->second;
	}
}
//check if 'path' is a path of a variable we need to update from the sim to us
bool SymbolTable::containsPathToUpdate(string path) {
	return this->pathsToVars.find(path) != this->pathsToVars.end()
		&& (this->var_names.find(pathsToVars.find(path)->second)->second->getConnc()==1);
}
//deletes a variable- can be used whenever they are defined inside a scope. (didn't use)
void SymbolTable::deleteVar(string varname) {
	mutex_lock.lock();
	//check if if the var exists
	if (this->var_names.find(varname) != this->var_names.end()) {
		//free the var
		delete (this->var_names.find(varname)->second);
		//delete from the map
		this->var_names.erase(varname);
	}
	else {
		cout << "error in deleting a var!" << endl;
		//exit(1);
	}
	//unlock the mutex
	mutex_lock.unlock();
}
//checks if the this var needs to be sent as an update to the simulator
bool SymbolTable::isUpdateToSim(string varname) {
	return this->var_names.find(varname) != this->var_names.end() &&
		(this->var_names.find(varname)->second->getConnc() == 0);
}

//in destructor, free the var_names variables as they are both local and updated