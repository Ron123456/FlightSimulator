//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_CHANGEVARCOMMAND_H
#define FLIGHTSIMULATOR_CHANGEVARCOMMAND_H
#include "Command.h"
#include "Compiler.h"
#include "ConditionParser.h"
class ChangeVarCommand : public Command{
public:
	int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_CHANGEVARCOMMAND_H
