#ifndef FLIGHTSIMULATOR_SYMBOLTABLE_H
#define FLIGHTSIMULATOR_SYMBOLTABLE_H
#include <queue> 
#include "Var.h"
#include <unordered_map>
#include <iostream>
#include <mutex>
/*
 class SymbolTable- holds mappings of variables and handles creating and updating them
*/
class SymbolTable {
public:
	//will have 3 maps- one with name to path,another path to name, and third will hold
	//the actual name to var
	//name of var in program as key
	unordered_map<string,Var*> var_names;
	//path name to var name
	unordered_map<string, string> pathsToVars;
	//var name to path name map
	unordered_map<string, string> varsToPaths;

	//connc value=1 means <-, and -> is 0,
	void createUpdateVar(string name, string path, bool connc);
	void createVar(string name,float val);
	void setValueFromName(string name,float val);
	void setValueFromPath(string path,float val);
	float get(string varname);
	bool containsPathToUpdate(string path);
	void deleteVar(string varname);
	//check to see if when chnaged, need to send a msg to the sim
	bool isUpdateToSim(string varname);
	//get the path in the sim for a name of an updating var (->)
	string getPath(string varname);
};
#endif