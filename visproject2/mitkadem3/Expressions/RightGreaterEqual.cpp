//
// Created by amitnir29 on 28/12/2019.
//

#include "RightGreaterEqual.h"
double RightGreaterEqual::calculate() {
    if (this->left->calculate() <= this->right->calculate()) {
        return 1;
    }
    return 0;
}
RightGreaterEqual::RightGreaterEqual(Expression *l, Expression *r) : BinaryOperator(l, r) {

}