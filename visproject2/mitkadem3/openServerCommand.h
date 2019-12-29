#ifndef FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
#define FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
#include "Compiler.h"
#include "Command.h"

class openServerCommand : public Command {
	bool openedConn = false;
public:
	int execute(Compiler* cp,string s) override;
	void openConnection(Compiler* cp, string s);
};
#endif
