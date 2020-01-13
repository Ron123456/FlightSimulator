//
// Created by amitnir29 on 06/01/2020.
//

#include "PrintCommand.h"
#include <string>
int PrintCommand::execute(Compiler* cp) {
    //get the string to print, it's after the 'Print' string

    //if starts with ", it's a string and we need to cut it
    string s =cp->token[cp->index + 1];
    if (s.rfind("\"", 0) == 0) {
        s = s.substr(1, s.length() - 2);
    }
    //else, it's an expression we need to interpet
    else {
		ConditionParser conParser = ConditionParser();
		float f = conParser.varsFromExp(s, cp);
        s = std::to_string(f);
    }

    cout << s << endl;
    //for next command
    return 2;

}