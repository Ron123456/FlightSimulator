//
// Created by amitnir29 on 28/12/2019.
//

#include "ConnectCommand.h"

int ConnectCommand::execute(Compiler *cp) {
	ConditionParser conParser = ConditionParser();
	//opens a connection using the expression interpretation to the port
    cp->connection.open(conParser.varsFromExp(cp->token[cp->index + 2], cp), cp->token[cp->index+1]);
    return 3;
}
