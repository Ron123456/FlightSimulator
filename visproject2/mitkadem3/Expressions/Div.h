//
// Created by amitnir on 12/11/2019.
//

#ifndef EX1__DIV_H_
#define EX1__DIV_H_

#include "BinaryOperator.h"
class Div : public BinaryOperator {
 public:
  Div(Expression* l, Expression* r);
  double calculate() override;
};

#endif //EX1__DIV_H_
