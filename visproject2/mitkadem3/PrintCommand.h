//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H
#include "Command.h"
#include "Compiler.h"
class PrintCommand : public Command {
	int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
