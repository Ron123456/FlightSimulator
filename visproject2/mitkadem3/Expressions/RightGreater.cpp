//
// Created by amitnir29 on 28/12/2019.
//

#include "RightGreater.h"
double RightGreater::calculate() {
    if (this->left->calculate() < this->right->calculate()) {
        return 1;
    }
    return 0;
}
RightGreater::RightGreater(Expression *l, Expression *r) : BinaryOperator(l, r) {}
