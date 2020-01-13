//
// Created by amitnir29 on 02/01/2020.
//

#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "Command.h"
#include "ConditionParser.h"
class WhileCommand : public Command {
public:
    //what the function basically do
    int execute(Compiler* cp) override;
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
