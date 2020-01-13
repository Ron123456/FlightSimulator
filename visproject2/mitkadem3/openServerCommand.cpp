#include "openServerCommand.h"

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <thread>
#include <chrono>
bool isOnlyNewlines(string s);
//hard coded XML file
static string listofvars[] = { "/instrumentation/airspeed-indicator/indicated-speed-kt","/sim/time/warp","/controls/switches/magnetos","//instrumentation/heading-indicator/offset-deg","/instrumentation/altimeter/indicated-altitude-ft","/instrumentation/altimeter/pressure-alt-ft","/instrumentation/attitude-indicator/indicated-pitch-deg","/instrumentation/attitude-indicator/indicated-roll-deg","/instrumentation/attitude-indicator/internal-pitch-deg","/instrumentation/attitude-indicator/internal-roll-deg","/instrumentation/encoder/indicated-altitude-ft","/instrumentation/encoder/pressure-alt-ft","/instrumentation/gps/indicated-altitude-ft","/instrumentation/gps/indicated-ground-speed-kt","/instrumentation/gps/indicated-vertical-speed","/instrumentation/heading-indicator/indicated-heading-deg","/instrumentation/magnetic-compass/indicated-heading-deg","/instrumentation/slip-skid-ball/indicated-slip-skid","/instrumentation/turn-indicator/indicated-turn-rate","/instrumentation/vertical-speed-indicator/indicated-speed-fpm","/controls/flight/aileron","/controls/flight/elevator","/controls/flight/rudder","/controls/flight/flaps","/controls/engines/engine/throttle","/controls/engines/current-engine/throttle","/controls/switches/master-avionics","/controls/switches/starter","/engines/active-engine/auto-start","/controls/flight/speedbrake","/sim/model/c172p/brake-parking","/controls/engines/engine/primer","/controls/engines/current-engine/mixture","/controls/switches/master-bat","/controls/switches/master-alt","/engines/engine/rpm" };
void openServerCommand::openConnection(Compiler* cp, string s) {
	ConditionParser conParser = ConditionParser();
	//we can get expressions as the port so we handle that
	int port= conParser.varsFromExp(s, cp);
	//creating a socket
	int sockid = socket(AF_INET, SOCK_STREAM, 0);
	if (sockid == -1) {
		cout << "error in openserver socket" << endl;
		exit(1);
	}
	//open connection to server
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;  //or INADDR_ANY
	address.sin_port = htons(port);
	int addrlen = sizeof(address);
	//bidning socket
	if (bind(sockid, (struct sockaddr *) &address, sizeof(address)) == -1) {
		exit(1);
	}
	//listening
	if (listen(sockid, 5) == -1) {
		cout << "listening open server failed" << endl;
		exit(1);
	}
	//this is the flight simulator socket
	int client_socket = accept(sockid, (struct sockaddr *) &address, (socklen_t*)&addrlen);
	if (client_socket == -1) {
		cout << "client_socket open server failed" << endl;
		exit(1);
	}
	//we listen for connection until the program is finished
	while (!cp->closeConnection) {
		//parse the data- we get float,float,float and need to put in the sys table, based on the XML data
		char buffer[1024];
		//read the data
		int valread = read(client_socket, buffer, 1024);
		//notify main that we can continue the running of it- we made a connection with the simulator
		if (!this->openedConn) {
			this->openedConn = true;
		}
		//to have no notes  on g++
		valread = valread;
		string buf(buffer);
		//it is possible to get more than 1 list of vars so we seperate by \n
		//buf is usually filled with \n at the end of it so we check for that as well
		while (buf.find("\n") != string::npos && !isOnlyNewlines(buf)) {
			string msg = buf.substr(0,buf.find("\n"));
			int index = 0;
			//interpet msg to update vals for sym table. iterate over every ','
			while (msg.find(",") != string::npos) {
				//if we saved a var with that path- update it
				if (cp->getSymbolTable()->containsPathToUpdate(listofvars[index])) {
					cp->getSymbolTable()->setValueFromPath(listofvars[index], stof(msg.substr(0,msg.find(","))));

				}
				//cut the string, continue to the next var
				msg = msg.substr(msg.find(",")+1, string::npos);
				cout << flush;
				index++;
			}
			//handle the last parameter
			if (cp->getSymbolTable()->containsPathToUpdate(listofvars[index])) {
				cp->getSymbolTable()->setValueFromPath(listofvars[index], stof(msg));
			}
			//cut the string to the next message we got (if exists)
			buf= buf.substr(buf.find("\n")+1,string::npos);
			
		}
	}
	//close listening socket
	close(sockid);
}

//creates a server that gets values
int openServerCommand::execute(Compiler* cp) {
	//block the main for only the first connection
	//std::thread thread1(this->openConnection,cp,s);
	string s = cp->token[cp->index+1];
	std::thread thread1(&openServerCommand::openConnection,this,cp,s);
	// Get starting timepoint 
	auto start = std::chrono::high_resolution_clock::now();
	//hold the main thread until connection is made
	while (!this->openedConn) {

	}
	//detach the thread from the current function
	
	thread1.detach();
	return 2;

}
//checks if all of the chars in the string are \n
bool isOnlyNewlines(string s) {
	//iterate over the string
	for (int i = 0; (unsigned int)i < s.length(); i++) {
		if (s[i] != '\n') {
			return false;
		}
	}
	return true;
}

