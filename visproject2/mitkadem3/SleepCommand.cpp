//
// Created by amitnir29 on 06/01/2020.
//

#include "SleepCommand.h"
#include <thread>
//make the thread sleep for X seconds
int SleepCommand::execute(Compiler* cp) {
	ConditionParser conParser = ConditionParser();
	//get the int from the tokens to sleep for number of seconds
	int num = conParser.varsFromExp(cp->token[cp->index + 1],cp);
	std::this_thread::sleep_for(std::chrono::milliseconds(num));
	return 2;

}