//
// Created by amitnir on 19/11/2019.
//

#ifndef EX1__UNARYEXPRESSION_H_
#define EX1__UNARYEXPRESSION_H_

#include "Expression.h"
class UnaryOperator : public Expression {
 protected:
  Expression* exp;
  UnaryOperator(Expression* expression);
 public:
  double calculate() override;
  virtual ~UnaryOperator();
};

#endif //EX1__UNARYEXPRESSION_H_
