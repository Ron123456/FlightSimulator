//
// Created by amitnir29 on 28/12/2019.
//

#include "Equal.h"
double Equal::calculate() {
    if (this->left->calculate() == this->right->calculate()) {
        return 1;
    }
    return 0;
}
Equal::Equal(Expression *l, Expression *r) : BinaryOperator(l, r) {

}