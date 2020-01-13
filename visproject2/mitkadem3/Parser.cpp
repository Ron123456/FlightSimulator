//
// Created by amitnir29 on 06/01/2020.
//

#include "Parser.h"
#include "Compiler.h"
/*#include "openServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ChangeVarCommand.h"*/
#include "Command.h"
#include "openServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ChangeVarCommand.h"
void Parser::parsing(Compiler *cp) {
    //while we can parse the next command
   while (cp->index < cp->token.size()) {
       //parse command if in map and return (only one command)
    if (this->commands.find(cp->token[cp->index]) != this->commands.end())
    {
        cp->index += this->commands.at(cp->token[cp->index])->execute(cp);
        return;
    }
    //not in map -> change variable
    else {
        ChangeVarCommand* changevar = new ChangeVarCommand();
        cp->index += changevar->execute(cp);
        return;
    }
  }
}

void Parser::createmap() {
    //create the map with the different commands identifiers and Command objects
    openServerCommand* openServerCommand1 = new openServerCommand();
    ConnectCommand* connectCommand = new ConnectCommand();
    DefineVarCommand* defineVarCommand = new DefineVarCommand();
    PrintCommand* printCommand = new PrintCommand();
    SleepCommand* sleepCommand = new SleepCommand();
    WhileCommand* whileCommand = new WhileCommand;
    IfCommand* ifCommand = new IfCommand();
	commands["openDataServer"] = openServerCommand1;
	commands.insert({"openDataServer", openServerCommand1});
    commands.insert({"connectControlClient", connectCommand});
    commands.insert({"var", defineVarCommand});
    commands.insert({"Print", printCommand});
    commands.insert({"Sleep", sleepCommand});
    commands.insert({"while",whileCommand});
    commands.insert({"if", ifCommand});

}

Parser::Parser() {}
