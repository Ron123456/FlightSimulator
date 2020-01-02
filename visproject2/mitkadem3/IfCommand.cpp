//
// Created by amitnir29 on 30/12/2019.
//

#include "IfCommand.h"
#include "ConditionParser.h"

int IfCommand::execute(Compiler *cp) {
    ConditionParser conditionParser = ConditionParser();
    if (conditionParser.execute(cp)) {

    }
}
