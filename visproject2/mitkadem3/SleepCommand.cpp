//
// Created by amitnir29 on 06/01/2020.
//

#include "SleepCommand.h"
#include <thread>
//make the thread sleep for X miliseconds
int SleepCommand::execute(Compiler* cp) {
	ConditionParser conParser = ConditionParser();
	//get the int from the tokens to sleep for number of seconds- it can be an expression
	int num = conParser.varsFromExp(cp->token[cp->index + 1],cp);
	//thread sleeps
	std::this_thread::sleep_for(std::chrono::milliseconds(num));
	//for next command
	return 2;

}
