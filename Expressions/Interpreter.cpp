//
// Created by amitnir on 19/11/2019.
//

#include <queue>
#include <stack>
#include <regex>
#include "Interpreter.h"
int precedence(char c);
bool isVar(char c);
vector<string> split(string str, char c);
Expression* Interpreter::interpret(string exp1) {
  string exp = "";
  for (int i=0; i<exp1.length(); i++) {
    if (exp1[i] == '+' || exp1[i] == '-') {
      if (i==0) {
        exp.append(1,'0');
      } else if (!isVar(exp1[i-1]) && exp1[i-1] != ')') {
        exp.append(1,'0');
      }
    }
    exp.append(1, exp1[i]);
    if (exp1[i] == '*' || exp1[i] == '/') {
      if (i==0) {
        throw "str not leagal";
      } else if (!isVar(exp1[i-1]) && exp1[i-1] != ')') {
        throw "str not leagal";
      }
    }
  }
  queue<string> postfix;
  stack<char> operators;
  for(int i = 0 ; i < exp.length(); i++) {
    string num = "";
    bool isNum = false;
    while (isVar(exp[i]) && i < exp.length()) {
      isNum = true;
      num.append(1, exp[i]);
      i++;
    }
    if (isNum) {
      postfix.push(num);
    }
    if(!(isVar(exp[i])) && exp[i] != '(' && exp[i] != ')') {
      while ((!operators.empty()) && (precedence(operators.top()) >= precedence(exp[i])) && (operators.top() != '(')) {
        string op = "";
        op.append(1, operators.top());
        operators.pop();
        postfix.push(op);
      }
      operators.push(exp[i]);
    }
    if(exp[i] == '(') {
      operators.push(exp[i]);
    }
    if(exp[i] == ')') {
      while (!operators.empty() && operators.top() != '(') {
        string op = "";
        op.append(1, operators.top());
        operators.pop();
        postfix.push(op);
      }
      if (operators.empty()) {
        throw "illigal";
      } else if (operators.top() == '(') {
        operators.pop();
      }
    }

  }
  while (!operators.empty()) {
    string op = "";
    op.append(1, operators.top());
    operators.pop();
    postfix.push(op);
  }

  stack<Expression*> exps;
  while (!postfix.empty()) {
    string oper = postfix.front();
    postfix.pop();
    bool isfound = false;;
    if (isVar(oper[0])) {
      if ('0' <= oper[0] && oper[0] <= '9') {
        exps.push(new Value(atof(oper.c_str())));
      } else {
        for (Variable* exp : variables) {
          if ((exp->GetName()).compare(oper) == 0) {
            isfound = true;
            exps.push(exp);
            break;
          }
        }
        if (!isfound) {
          throw "not exisrt var";
        }
      }
    } else {
      if (oper == "+") {
        Expression* right = exps.top();
        exps.pop();
        Expression* left = exps.top();
        exps.pop();
        exps.push(new Plus(left, right));
      } else if (oper == "-") {
        Expression* right = exps.top();
        exps.pop();
        Expression* left = exps.top();
        exps.pop();
        exps.push(new Minus(left, right));
      } else if (oper == "*") {
        Expression* right = exps.top();
        exps.pop();
        Expression* left = exps.top();
        exps.pop();
        exps.push(new Mul(left, right));
      } else if (oper == "/") {
        Expression* right = exps.top();
        exps.pop();
        Expression* left = exps.top();
        exps.pop();
        exps.push(new Div(left, right));
      }
    }
  }

  Expression* ret = exps.top();
  return ret;

}
void Interpreter::setVariables(string vars) {

  vector<string> splt = split(vars, ';');
  for (string s : splt) {
    vector<string> nameval = split(s, '=');
    if(!regex_search(nameval[0],regex("^(_*[a-zA-Z][0-9]*)+$"))) {
      throw "not leaagallll name";
    }
    if(!regex_search(nameval[1],regex(R"(^-?\d+(\.\d+)?$)"))) {
      throw "not leaagallll num";
    }
    bool isexist = false;
    for (Variable* v : variables) {
      if ((v->GetName()).compare(nameval[0]) == 0) {
        isexist = true;
        v->SetValue(atof(nameval[1].c_str()));
      }
    }
    if (!isexist) {
      variables.push_back(new Variable(nameval[0], atof(nameval[1].c_str())));
    }

  }

}
bool isVar(char c) {
  return (c != '*' && c != '+' && c != '-' && c != '/' && c != '(' && c != ')');
}
int precedence(char c) {
  if(c == '*' || c == '/') {
    return 2;
  } else if(c == '+' || c == '-') {
    return 1;
  } else {
    return 0;
  }
}

vector<string> split(string str, char c) {
  vector<string> vars;
  string s;
  for (int i = 0; i < str.length(); i++) {
    s = "";
    while (i<str.length() && str[i] != c) {
      s.append(1, str[i]);
      i++;
    }
    vars.push_back(s);
  }
  return vars;
}
