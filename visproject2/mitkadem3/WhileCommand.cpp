//
// Created by amitnir29 on 02/01/2020.
//

#include "WhileCommand.h"
int execute(Compiler* cp) {
    ConditionParser conditionParser = ConditionParser();
    int whileindex = cp->index;
    //after the {
    int loopindex = cp->index+5;
    int cond = conditionParser.execute(cp);
    int endindex;
    while (cond) {
        cp->index = loopindex;
        while (cp->token[cp->index] != "}") {
            cp->parser->parsing(cp);
        }
        endindex = cp->index;
        cp->index = whileindex;
        cond = conditionParser.execute(cp);
    }
    cp->index = endindex;
    //skip the }
    return 1;
    /*if (conditionParser.execute(cp)) {
        //skip the condition and the {
        cp->index = cp->index + 5;
        while (cp->token[cp->index] != "}") {
            cp->parser->parsing(cp);
        }
    }*/

}