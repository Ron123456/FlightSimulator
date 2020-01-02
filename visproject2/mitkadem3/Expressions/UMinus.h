//
// Created by amitnir on 19/11/2019.
//

#ifndef EX1__UMINUS_H_
#define EX1__UMINUS_H_

#include "UnaryOperator.h"
class UMinus : public UnaryOperator {
 public:
  UMinus(Expression* e);
  double calculate() override;
};

#endif //EX1__UMINUS_H_
