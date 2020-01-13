//
// Created by amitnir29 on 30/12/2019.
//

#include "IfCommand.h"
#include "ConditionParser.h"

int IfCommand::execute(Compiler *cp) {
    ConditionParser conditionParser = ConditionParser();
    //if the condition is true
    if (conditionParser.execute(cp)) {
        //skip the condition and the {
        cp->index = cp->index + 5;
        //while there are commands, execute
        while (cp->token[cp->index] != "}") {
            cp->parser->parsing(cp);
        }
    }
    //condition is false
    else {
        //get the index to the end
        while (cp->token[cp->index] != "}") {
            cp->index++;
        }
    }
    //skip }
    return 1;
}
