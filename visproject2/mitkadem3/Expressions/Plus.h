//
// Created by amitnir on 11/11/2019.
//

#ifndef EX1__PLUS_H_
#define EX1__PLUS_H_

#include "BinaryOperator.h"
#include "Expression.h"
class Plus : public BinaryOperator {
 public:
  Plus(Expression* l, Expression* r);
  double calculate() override;

};

#endif //EX1__PLUS_H_
