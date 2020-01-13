//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_DEFINEVARCOMMAND_H
#define FLIGHTSIMULATOR_DEFINEVARCOMMAND_H
#include "Command.h"
#include "Compiler.h"
#include "ConditionParser.h"
class DefineVarCommand : public Command{
    //what the function basically do
	int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_DEFINEVARCOMMAND_H
