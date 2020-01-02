//
// Created by amitnir on 19/11/2019.
//

#ifndef EX1__INTERPRETER_H_
#define EX1__INTERPRETER_H_

#include "ex1.h"
#include <vector>

class Interpreter {
  vector<Variable*> variables;
 public:
  static Expression* interpret(string exp);
  void setVariables(string vars);
};

#endif //EX1__INTERPRETER_H_
