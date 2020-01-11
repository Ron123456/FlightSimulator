//
// Created by amitnir29 on 28/12/2019.
//

#include "ConnectCommand.h"

int ConnectCommand::execute(Compiler *cp) {
    cp->connection.open(atoi(cp->token[cp->index+2].c_str()), cp->token[cp->index+1]);
    return 3;
}
