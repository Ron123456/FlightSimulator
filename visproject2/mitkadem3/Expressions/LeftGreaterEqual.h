//
// Created by amitnir29 on 28/12/2019.
//

#ifndef FLIGHTSIMULATOR_LEFTGREATEREQUAL_H
#define FLIGHTSIMULATOR_LEFTGREATEREQUAL_H


#include "BinaryOperator.h"
#include "Expression.h"
class LeftGreaterEqual : public BinaryOperator {
public:
    LeftGreaterEqual(Expression* l, Expression* r);
    //Will return 1 = true, 0 = false.
    double calculate() override;

};


#endif //FLIGHTSIMULATOR_LEFTGREATEREQUAL_H
