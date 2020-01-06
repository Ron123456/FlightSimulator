//
// Created by amitnir29 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR_PARSER_H
#define FLIGHTSIMULATOR_PARSER_H

#include "map"
#include "Compiler.h"

class Parser {
    map<string, Command> commands;
public:
    void parsing(Compiler* cp);
};


#endif //FLIGHTSIMULATOR_PARSER_H
