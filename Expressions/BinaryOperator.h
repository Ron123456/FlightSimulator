//
// Created by amitnir on 11/11/2019.
//

#ifndef EX1__BINARYOPERATOR_H_
#define EX1__BINARYOPERATOR_H_

#include "Expression.h"
class BinaryOperator : public Expression {
 protected:
  Expression* left;
  Expression* right;
  BinaryOperator(Expression* lef, Expression* rig);
 public:
  double calculate() override;
  virtual ~BinaryOperator();
};

#endif //EX1__BINARYOPERATOR_H_
