//
// Created by amitnir29 on 28/12/2019.
//
#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H
#include <string>
#include "Compiler.h"
#include "Connection.h"
#include "ConditionParser.h"

class ConnectCommand : public Command {
public:
    //the execute - what the command basically does
	int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
