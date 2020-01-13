//
// Created by amitnir29 on 30/12/2019.
//

#ifndef FLIGHTSIMULATOR_CONDITIONPARSER_H
#define FLIGHTSIMULATOR_CONDITIONPARSER_H


#include "Compiler.h"
#include "Command.h"
#include "Expressions/Interpreter.h"


class ConditionParser : public Command {
public:
    //for an old generation of the code
    vector<Command> commandsList(Compiler* compiler);

    //this method recives a expression with variables in them and replaces them with values
    double varsFromExp(string& exp, Compiler* compiler);

    //check if c is a number
    bool isNumber(char c);

    //check if c is an operator
    bool isOperator(char c);

    //check if c is ( or )
    bool isParenthesis(char c);

    //checks if the condition in the token is true (returns 1) or false (0(
    int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
