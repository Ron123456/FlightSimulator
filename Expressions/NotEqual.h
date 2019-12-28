//
// Created by amitnir29 on 28/12/2019.
//

#ifndef FLIGHTSIMULATOR_NOTEQUAL_H
#define FLIGHTSIMULATOR_NOTEQUAL_H

#include "BinaryOperator.h"
#include "Expression.h"
class NotEqual : public BinaryOperator {
public:
    NotEqual(Expression* l, Expression* r);
    //Will return 1 = true, 0 = false.
    double calculate() override;

};


#endif //FLIGHTSIMULATOR_NOTEQUAL_H
