//
// Created by amitnir on 12/11/2019.
//

#include "Minus.h"
double Minus::calculate() {
  return (this->left->calculate() - this->right->calculate());
}
Minus::Minus(Expression *l, Expression *r) : BinaryOperator(l, r) {

}
