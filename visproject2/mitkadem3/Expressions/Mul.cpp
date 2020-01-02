//
// Created by amitnir on 12/11/2019.
//

#include "Mul.h"
double Mul::calculate() {
  return (this->left->calculate() *  this->right->calculate());
}
Mul::Mul(Expression *l, Expression *r) : BinaryOperator(l, r) {

}
