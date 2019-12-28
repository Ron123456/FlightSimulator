//
// Created by amitnir29 on 28/12/2019.
//

#ifndef FLIGHTSIMULATOR_RIGHTGREATER_H
#define FLIGHTSIMULATOR_RIGHTGREATER_H


#include "BinaryOperator.h"
#include "Expression.h"
class RightGreater : public BinaryOperator {
public:
    RightGreater(Expression* l, Expression* r);
    //Will return 1 = true, 0 = false.
    double calculate() override;

};;


#endif //FLIGHTSIMULATOR_RIGHTGREATER_H
