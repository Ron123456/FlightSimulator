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
class Compiler;


class Parser {
	//map of commands, O(1) for each
	std::map<std::string, Command*> commands;
public:
    //create the map
    void createmap();
    //parse the next command
    void parsing(Compiler* cp);
    //constractor
    Parser();
};


#endif //FLIGHTSIMULATOR_PARSER_H
