//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H

#include "Command.h"
#include "Compiler.h"
#include "ConditionParser.h"
class SleepCommand : public Command{
public:
    //what the function basically do
	int execute(Compiler* cp) override;

};


#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
