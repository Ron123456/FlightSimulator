//
// Created by amitnir29 on 30/12/2019.
//

#include "ConditionParser.h"


double ConditionParser::varsFromExp(string &exp, Compiler* compiler) {
    Interpreter interpreter;
    string var = "";
    string newexp = "";
    for (int i=0; i<exp.length(); i++) {
        char c = exp.at(i);
		//cout << "char is " << c << endl;
        //if char c is not a variable
        if (isNumber(c) || isOperator(c) || isParenthesis(c) || c == ' ' || c== '.') {
			//cout << "not in var" << endl;
            newexp.append(1, c);
        } else {
			//cout << "inside var" << endl;
            //while that's a variable
            //while ((!(isNumber(c) || isOperator(c) || isParenthesis(c) || c == ' ')) && i < exp.length()) {
            while ((!(isOperator(c) || isParenthesis(c) || c == ' ')) && i < exp.length()) {
                var.append(1,exp.at(i));
                i++;
                c = exp.at(i);
            }
            //find variable's value
            float val = compiler->getSymbolTable()->get(var);
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
    //Interpreter interpreter;
    // lexer returns While,leftexp,operator,rightexp
    double left = varsFromExp(cp->token[cp->index + 1], cp);
    string oper = cp->token[cp->index + 2];
    double right = varsFromExp(cp->token[cp->index + 3], cp);
    //left = interpreter.interpret(leftexp)->calculate();
    //right = interpreter.interpret(rightexp)->calculate();
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



