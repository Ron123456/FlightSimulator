//
// Created by amitnir29 on 30/12/2019.
//

#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H


#include "Command.h"

class IfCommand : public Command {
public:
    int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_IFCOMMAND_H
