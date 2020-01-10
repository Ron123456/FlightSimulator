//
// Created by amitnir29 on 09/01/2020.
//

#ifndef FLIGHTSIMULATOR_FUNCTIONCOMMAND_H
#define FLIGHTSIMULATOR_FUNCTIONCOMMAND_H


#include "Command.h"

class FunctionCommand : public Command {
public:
    int execute(Compiler* cp) override;

};


#endif //FLIGHTSIMULATOR_FUNCTIONCOMMAND_H
