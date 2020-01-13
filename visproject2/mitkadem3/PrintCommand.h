//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H
#include "Command.h"
#include "Compiler.h"
#include "ConditionParser.h"
class PrintCommand : public Command {
public:
    //what the function basically do
	int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
