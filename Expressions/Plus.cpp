//
// Created by amitnir on 11/11/2019.
//

#include "Plus.h"
double Plus::calculate() {
  return (this->left->calculate() + this->right->calculate());
}
Plus::Plus(Expression *l, Expression *r) : BinaryOperator(l, r) {

}
