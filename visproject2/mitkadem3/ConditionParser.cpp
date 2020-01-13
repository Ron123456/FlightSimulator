//
// Created by amitnir29 on 30/12/2019.
//

#include "ConditionParser.h"


double ConditionParser::varsFromExp(string &exp, Compiler* compiler) {
    Interpreter interpreter;
    //the variable we want to replace
    string var = "";
    //the new expression with the values
    string newexp = "";
    //for each character
    for (int i=0; i<exp.length(); i++) {
        char c = exp.at(i);
        //if char c is not a variable
        if (isNumber(c) || isOperator(c) || isParenthesis(c) || c == ' ' || c== '.') {
			//just append to new expression
            newexp.append(1, c);
        } else {;
            //while that's a variable
            while ((!(isOperator(c) || isParenthesis(c) || c == ' ')) && i < exp.length()) {
                var.append(1,exp.at(i));
                i++;
                if (i < exp.length()) {
                    c = exp.at(i);
                }
            }
            //find variable's value
            float val = compiler->getSymbolTable()->get(var);
            var = to_string(val);
            //if its -- its a + cause we don't know to deal with --.
            if (var[0] == '-' && newexp[newexp.length() - 1] == '-') {
                newexp = newexp.substr(0, newexp.length() - 1);
            }
            //append the value
            newexp.append(var);

            //for next iteration
            var = "";
        }
    }
    //return the interperted value of new expression
    return interpreter.interpret(newexp)->calculate();
}

bool ConditionParser::isNumber(char c) {
    return ('0' <= c && c<='9');
}

bool ConditionParser::isOperator(char c) {
    return ((c=='+')||(c=='-')||(c=='*')||(c=='/'));
}

bool ConditionParser::isParenthesis(char c) {
    return ((c=='(') || (c==')'));
}

int ConditionParser::execute(Compiler *cp) {
    // calculate left & right expressions
    double left = varsFromExp(cp->token[cp->index + 1], cp);
    string oper = cp->token[cp->index + 2];
    double right = varsFromExp(cp->token[cp->index + 3], cp);
    //according to which operator, check if the condition is true or false:
    if (oper == "==") {
        if (left == right) {
            return 1;
        }
        return 0;
    } else if (oper == "!=") {
        if (left != right) {
            return 1;
        }
        return 0;
    } else if (oper == ">=") {
        if (left >= right) {
            return 1;
        }
        return 0;
    } else if (oper == ">") {
        if (left > right) {
            return 1;
        }
        return 0;
    } else if (oper == "<=") {
        if (left <= right) {
            return 1;
        }
        return 0;
    } else if (oper == "<") {
        if (left < right) {
            return 1;
        }
        return 0;
    } else {
        throw "something happend in ConditionParser";
    }

    // 0 because we will call it from the while
    return 0;
}

vector<Command> ConditionParser::commandsList(Compiler *compiler) {
    vector<Command> commands;
    int index, startindex = compiler->index;
    while (compiler->token[startindex] != "{") {
        startindex++;
    }
    startindex++;
    index = startindex;
    //TODO IN THE PARSER

}

//ConditionParser::ConditionParser(Compiler *comp) {
//    compiler = comp;
//}



