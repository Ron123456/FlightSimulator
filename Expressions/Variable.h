//
// Created by amitnir on 11/11/2019.
//
#include <string>
#include "Expression.h"
using namespace std;
#ifndef EX1__VARIABLE_H_
#define EX1__VARIABLE_H_

class Variable : public Expression {
  string name;
  double value;
 public:
  Variable(const string &name, double value);
  Variable& operator++();
  Variable& operator--();
  Variable& operator+=(double val);
  Variable& operator-=(double val);
  Variable& operator++(int);
  Variable& operator--(int);
  void SetValue(double value);
  const string &GetName() const;
  double calculate() override;
};

#endif //EX1__VARIABLE_H_
