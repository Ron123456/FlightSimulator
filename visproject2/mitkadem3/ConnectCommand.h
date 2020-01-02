//
// Created by amitnir29 on 28/12/2019.
//
#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H
#include <string>
#include "Compiler.h"



class ConnectCommand : public Command {
public:
	int execute(Compiler* cp) override { return 1; };
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
