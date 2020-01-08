//
// Created by amitnir29 on 30/12/2019.
//

#include "IfCommand.h"
#include "ConditionParser.h"

int IfCommand::execute(Compiler *cp) {
    ConditionParser conditionParser = ConditionParser();
    if (conditionParser.execute(cp)) {
        //skip the condition and the {
        cp->index = cp->index + 5;
        while (cp->token[cp->index] != "}") {
            cp->parser->parsing(cp);
        }
    }
    //skip }
    return 1;
}
