//
// Created by amitnir on 12/11/2019.
//

#include "Div.h"
double Div::calculate() {
  return (this->left->calculate() / this->right->calculate());
}
Div::Div(Expression *l, Expression *r) : BinaryOperator(l, r) {
  if (r->calculate() == 0) {
    throw "div0";
  }
}
