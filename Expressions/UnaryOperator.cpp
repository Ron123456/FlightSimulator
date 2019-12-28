//
// Created by amitnir on 19/11/2019.
//


#include "UnaryOperator.h"

UnaryOperator::UnaryOperator(Expression *expression) {
  exp = expression;
}
double UnaryOperator::calculate() {
  return exp->calculate();
}
UnaryOperator::~UnaryOperator() {
  delete exp;
}
