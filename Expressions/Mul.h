//
// Created by amitnir on 12/11/2019.
//

#ifndef EX1__MUL_H_
#define EX1__MUL_H_

#include "BinaryOperator.h"
class Mul : public BinaryOperator {
 public:
  Mul(Expression* l, Expression* r);
  double calculate() override;
};

#endif //EX1__MUL_H_
