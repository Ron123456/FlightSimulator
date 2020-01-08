//
// Created by amitnir29 on 06/01/2020.
//

#include "Parser.h"
#include "openServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ChangeVarCommand.h"

void Parser::parsing(Compiler *cp) {
    //while (cp->index < cp->token.size()) {
    if (commands.find(cp->token[cp->index]) != commands.end())
    {
        cp->index += commands.at(cp->token[cp->index])->execute(cp);
    }
    else {
        //TODO see how changeVar works
        ChangeVarCommand* changevar =
    }
   //}
}

void Parser::createmap() {
    openServerCommand* openServerCommand1 = new openServerCommand();
    ConnectCommand* connectCommand = new ConnectCommand();
    DefineVarCommand* defineVarCommand = new DefineVarCommand();
    PrintCommand* printCommand = new PrintCommand();
    SleepCommand* sleepCommand = new SleepCommand();
    WhileCommand* whileCommand = new WhileCommand;
    IfCommand* ifCommand = new IfCommand();
    commands.insert({"openDataServer", openServerCommand1});
    commands.insert({"connectControlClient", connectCommand});
    commands.insert({"var", defineVarCommand});
    commands.insert({"Print", printCommand});
    commands.insert({"Sleep", sleepCommand});
    commands.insert({"while",whileCommand});
    commands.insert({"if", ifCommand});

}
