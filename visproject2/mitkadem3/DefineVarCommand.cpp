//
// Created by amitnir29 on 06/01/2020.
//
#include "DefineVarCommand.h"
int DefineVarCommand::execute(Compiler* cp) {
	//get the name of var
	string varName = cp->token[cp->index + 1];
	//get the operator of the definition
	string op= cp->token[cp->index + 2];
	if (op.compare("->") == 0) {
		//connc=0 means ->
		string path = cp->token[cp->index + 4];
		//delete the quotes from the string 
		path = path.substr(1, path.length() - 2);
		cp->getSymbolTable().createUpdateVar(varName, path, 0);
		return 5;
	}
	else if (op.compare("<-") == 0) {
		//connc=1 means <-
		string path = cp->token[cp->index + 4];
		//delete the quotes from the string 
		path = path.substr(1, path.length()-2);
		cp->getSymbolTable().createUpdateVar(varName, path, 1);
		return 5;
	}
	//it is a normal var then
	else if (op.compare("=") == 0) {
		//get the expression
		string expression= cp->token[cp->index + 3];
		//calc the val using ConditionParser
		ConditionParser conParser = ConditionParser();
        double val =conParser.varsFromExp(expression, cp);
		//TODO that f=val
		float f = val;
		cp->getSymbolTable().createVar(varName,f);
		return 3;
	}
	//shuldn't get to here
	return 3;

}