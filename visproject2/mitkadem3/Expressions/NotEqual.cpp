//
// Created by amitnir29 on 28/12/2019.
//

#include "NotEqual.h"
double NotEqual::calculate() {
    if (this->left->calculate() != this->right->calculate()) {
        return 1;
    }
    return 0;
}
NotEqual::NotEqual(Expression *l, Expression *r) : BinaryOperator(l, r) {}