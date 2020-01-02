//
// Created by amitnir29 on 02/01/2020.
//

#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "Command.h"

class WhileCommand : public Command {

public:
    int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
