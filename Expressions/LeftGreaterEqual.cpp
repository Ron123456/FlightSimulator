//
// Created by amitnir29 on 28/12/2019.
//

#include "LeftGreaterEqual.h"
double LeftGreaterEqual::calculate() {
    if (this->left->calculate() >= this->right->calculate()) {
        return 1;
    }
    return 0;
}
LeftGreaterEqual::LeftGreaterEqual(Expression *l, Expression *r) : BinaryOperator(l, r) {

}