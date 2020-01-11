//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_PARSER_H
#define FLIGHTSIMULATOR_PARSER_H

#include <map>
#include <string>
/*#include "Command.h"
#include "openServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ChangeVarCommand.h"*/
class Command;
class openServerCommand;
class ConnectCommand;
class DefineVarCommand;
class PrintCommand;
class SleepCommand;
class WhileCommand;
class IfCommand;
class ChnageVarCommand;
//#include "ChangeVarCommand.h"
//#include "Compiler.h"
class Compiler;
class Parser {
	/*openServerCommand* openServerCommand1 = new openServerCommand();
	ConnectCommand* connectCommand = new ConnectCommand();
	DefineVarCommand* defineVarCommand = new DefineVarCommand();
	PrintCommand* printCommand = new PrintCommand();
	SleepCommand* sleepCommand = new SleepCommand();
	WhileCommand* whileCommand = new WhileCommand;
	IfCommand* ifCommand = new IfCommand();
	unordered_map<string, Command*> commands = {
	{ "openDataServer", openServerCommand1 },
	{ "connectControlClient" , connectCommand },
	{ "var" ,defineVarCommand }, { "Print",printCommand },
	{ "Sleep" , sleepCommand }, { "while" , whileCommand },
	{ "if" , ifCommand } 
	};*/
	std::map<std::string, Command*> commands;
	//map<string,int
public:
    void createmap();
    void parsing(Compiler* cp);

    Parser();
};


#endif //FLIGHTSIMULATOR_PARSER_H
