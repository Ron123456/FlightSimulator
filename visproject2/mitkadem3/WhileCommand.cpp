//
// Created by amitnir29 on 02/01/2020.
//

#include "WhileCommand.h"
int execute(Compiler* cp) {
    ConditionParser conditionParser = ConditionParser();
    int whileindex = cp->index;
    //after the {
    int loopindex = cp->index+5;
    int firstTime = conditionParser.execute(cp);
    /*if (conditionParser.execute(cp)) {
        //skip the condition and the {
        cp->index = cp->index + 5;
        while (cp->token[cp->index] != "}") {
            cp->parser->parsing(cp);
        }
    }*/

}