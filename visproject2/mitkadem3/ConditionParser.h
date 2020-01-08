//
// Created by amitnir29 on 30/12/2019.
//

#ifndef FLIGHTSIMULATOR_CONDITIONPARSER_H
#define FLIGHTSIMULATOR_CONDITIONPARSER_H


#include "Compiler.h"
#include "Command.h"
#include "Expressions/Interpreter.h"


class ConditionParser : public Command {
    //Compiler* compiler;
public:
    vector<Command> commandsList(Compiler* compiler);

    double varsFromExp(string& exp, Compiler* compiler);

    bool isNumber(char c);
    bool isOperator(char c);
    bool isParenthesis(char c);
    int execute(Compiler* cp) override;


};


#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
