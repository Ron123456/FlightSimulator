//
// Created by amitnir on 19/11/2019.
//

#include "UMinus.h"
UMinus::UMinus(Expression *e) : UnaryOperator(e) {

}
double UMinus::calculate() {
  return (-(exp->calculate()));
}
