//
// Created by amitnir on 11/11/2019.
//

#ifndef EX1__VALUE_H_
#define EX1__VALUE_H_

#include "Expression.h"

class Value : public Expression {
 private:
  double val;
 public:
  explicit Value(double val);
  double calculate() override;
};

#endif //EX1__VALUE_H_
