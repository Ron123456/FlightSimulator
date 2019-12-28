//
// Created by amitnir29 on 28/12/2019.
//

#ifndef FLIGHTSIMULATOR_LEFTGREATER_H
#define FLIGHTSIMULATOR_LEFTGREATER_H

#include "BinaryOperator.h"
#include "Expression.h"
class LeftGreater : public BinaryOperator {
public:
    LeftGreater(Expression* l, Expression* r);
    //Will return 1 = true, 0 = false.
    double calculate() override;

};


#endif //FLIGHTSIMULATOR_LEFTGREATER_H
