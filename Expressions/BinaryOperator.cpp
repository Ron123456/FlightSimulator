//
// Created by amitnir on 11/11/2019.
//

#include "BinaryOperator.h"
double BinaryOperator::calculate() {
  return 0;
}
BinaryOperator::BinaryOperator(Expression *lef, Expression *rig) {
  this->left=lef;
  this->right=rig;
}
BinaryOperator::~BinaryOperator() {
  delete left;
  delete right;
}
