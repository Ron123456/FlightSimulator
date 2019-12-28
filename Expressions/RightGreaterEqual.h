//
// Created by amitnir29 on 28/12/2019.
//

#ifndef FLIGHTSIMULATOR_RIGHTGREATEREQUAL_H
#define FLIGHTSIMULATOR_RIGHTGREATEREQUAL_H


#include "BinaryOperator.h"
#include "Expression.h"
class RightGreaterEqual : public BinaryOperator {
public:
    RightGreaterEqual(Expression* l, Expression* r);
    //Will return 1 = true, 0 = false.
    double calculate() override;

};


#endif //FLIGHTSIMULATOR_RIGHTGREATEREQUAL_H
