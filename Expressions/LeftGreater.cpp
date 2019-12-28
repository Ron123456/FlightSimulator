//
// Created by amitnir29 on 28/12/2019.
//

#include "LeftGreater.h"
double LeftGreater::calculate() {
    if (this->left->calculate() > this->right->calculate()) {
        return 1;
    }
    return 0;
}
LeftGreater::LeftGreater(Expression *l, Expression *r) : BinaryOperator(l, r) {

}
