//
// Created by amitnir29 on 06/01/2020.
//

#include "PrintCommand.h"
#include <string>
int PrintCommand::execute(Compiler* cp) {
	//get the string to print, it's after the 'Print' string
	string s =cp->token[cp->index + 1];
	cout << s << endl;
	return 2;

}