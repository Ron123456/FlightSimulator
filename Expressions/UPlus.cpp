//
// Created by amitnir on 19/11/2019.
//

#include "UPlus.h"
UPlus::UPlus(Expression *e) : UnaryOperator(e) {

}
double UPlus::calculate() {
  return exp->calculate();
}
