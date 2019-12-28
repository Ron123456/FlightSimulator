//
// Created by amitnir on 12/11/2019.
//

#ifndef EX1__MINUS_H_
#define EX1__MINUS_H_

#include "BinaryOperator.h"
class Minus : public BinaryOperator {
 public:
  Minus(Expression* l, Expression* r);
  double calculate() override;
};

#endif //EX1__MINUS_H_
