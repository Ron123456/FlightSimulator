//
// Created by amitnir29 on 02/01/2020.
//

#include "WhileCommand.h"
int WhileCommand::execute(Compiler* cp) {
    ConditionParser conditionParser = ConditionParser();
    //remember the initial index
    int whileindex = cp->index;
    //after the { - to return to when we need to do again
    int loopindex = cp->index+5;
    //the first time the condition
    int cond = conditionParser.execute(cp);
    int endindex;

    //if the condition was false, get to the end
    if(!cond) {
        while (cp->token[cp->index] != "}") {
            cp->index++;
        }
        //put the end in the end index
        endindex = cp->index;
    }

    //else, condition was true then do the while
    while (cond) {
        cp->index = loopindex;
        //while there are commands to execute, execute
        while (cp->token[cp->index] != "}") {
            cp->parser->parsing(cp);
        }
        //put the end in the end index
        endindex = cp->index;
        //for next iteration
        cp->index = whileindex;
        //calculate the condition again
        cond = conditionParser.execute(cp);
    }
    //put the index in the end
    cp->index = endindex;

    //skip the }
    return 1;

}