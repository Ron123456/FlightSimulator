//
// Created by amitnir29 on 28/12/2019.
//

#ifndef FLIGHTSIMULATOR_EQUAL_H
#define FLIGHTSIMULATOR_EQUAL_H

#include "BinaryOperator.h"
#include "Expression.h"
class Equal : public BinaryOperator {
public:
    Equal(Expression* l, Expression* r);
    //Will return 1 = true, 0 = false.
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_EQUAL_H
