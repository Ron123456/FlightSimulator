//
// Created by amitnir on 11/11/2019.
//

#include "Variable.h"
Variable::Variable(const string &name, double value) : name(name), value(value) {}
Variable &Variable::operator++() {
  value++;
  return *this;
}
Variable &Variable::operator--() {
  value--;
  return *this;
}
Variable &Variable::operator+=(double val) {
  value += val;
  return *this;
}
Variable &Variable::operator-=(double val) {
  value -= val;
  return *this;
}
Variable &Variable::operator++(int) {
  value++;
  return *this;
}
Variable &Variable::operator--(int) {
  value--;
  return *this;
}
double Variable::calculate() {
  return value;
}
const string &Variable::GetName() const {
  return name;
}
void Variable::SetValue(double value) {
  Variable::value = value;
}
