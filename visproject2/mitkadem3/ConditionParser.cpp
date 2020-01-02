//
// Created by amitnir29 on 30/12/2019.
//

#include "ConditionParser.h"



string ConditionParser::varsFromExp(string &exp, Compiler* compiler) {
    string var = "";
    string newexp = "";
    for (int i=0; i<exp.length(); i++) {
        char c = exp.at(i);
        //if char c is not a variable
        if (isNumber(c) || isOperator(c) || isParenthesis(c) || c == ' ') {
            newexp.append(1, c);
        } else {
            //while that's a variable
            while ((!(isNumber(c) || isOperator(c) || isParenthesis(c) || c == ' ')) && i < exp.length()) {
                var.append(1,exp.at(i));
                i++;
                c = exp.at(i);
            }
            //find variable's value
            float val = compiler->getSymbolTable().get(var);
            //TODO check float instead of int
            var = to_string(val);
            //if its -- its a + cause we don't know to deal with --.
            if (var[0] == '-' && newexp[newexp.length() - 1] == '-') {
                newexp = newexp.substr(0, newexp.length() - 1);
            }
            newexp.append(var);

            //for next iteration
            var = "";
        }
    }
    return newexp;
}

bool ConditionParser::isNumber(char c) {
    return ('0' <= c && c>='9');
}

bool ConditionParser::isOperator(char c) {
    return ((c=='+')||(c=='-')||(c=='*')||(c=='/'));
}

bool ConditionParser::isParenthesis(char c) {
    return ((c=='(') || (c==')'));
}

int ConditionParser::execute(Compiler *cp) {
    // lexer returns While,leftexp,operator,rightexp
    string leftexp = cp->token[cp->index + 1];
    string oper = cp->token[cp->index + 2];
    string rightexp = cp->token[cp->index + 3];
    double left = 0, right = 0;
    left = Interpreter::interpret(leftexp)->calculate();
    right = Interpreter::interpret(rightexp)->calculate();
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



