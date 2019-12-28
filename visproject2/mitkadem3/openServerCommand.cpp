#include "openServerCommand.h"
#include <sys/socket.h>
#include <netinet/in.h> 
//maybe not needed
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <thread>
static string listofvars[] = { "/instrumentation/airspeed-indicator/indicated-speed-kt","/sim/time/warp","/controls/switches/magnetos","//instrumentation/heading-indicator/offset-deg","/instrumentation/altimeter/indicated-altitude-ft","/instrumentation/altimeter/pressure-alt-ft","/instrumentation/attitude-indicator/indicated-pitch-deg","/instrumentation/attitude-indicator/indicated-roll-deg","/instrumentation/attitude-indicator/internal-pitch-deg","/instrumentation/attitude-indicator/internal-roll-deg","/instrumentation/encoder/indicated-altitude-ft","/instrumentation/encoder/pressure-alt-ft","/instrumentation/gps/indicated-altitude-ft","/instrumentation/gps/indicated-ground-speed-kt","/instrumentation/gps/indicated-vertical-speed","/instrumentation/heading-indicator/indicated-heading-deg","/instrumentation/magnetic-compass/indicated-heading-deg","/instrumentation/slip-skid-ball/indicated-slip-skid","/instrumentation/turn-indicator/indicated-turn-rate","/instrumentation/vertical-speed-indicator/indicated-speed-fpm","/controls/flight/aileron","/controls/flight/elevator","/controls/flight/rudder","/controls/flight/flaps","/controls/engines/engine/throttle","/controls/engines/current-engine/throttle","/controls/switches/master-avionics","/controls/switches/starter","/engines/active-engine/auto-start","/controls/flight/speedbrake","/sim/model/c172p/brake-parking","/controls/engines/engine/primer","/controls/engines/current-engine/mixture","/controls/switches/master-bat","/controls/switches/master-alt","/engines/engine/rpm" };
void openServerCommand::openConnection(Compiler cp, string s) {
	//get port somehow- depends on parser
	int port=5400;
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
	if (bind(sockid, (struct sockaddr *) &address, sizeof(address)) == -1) {
		exit(1);
	}

	if (listen(sockid, 5) == -1) {
		cout << "listening open server failed" << endl;
		exit(1);
	}
	while (true) {
		//this is the flight simulator socket
		int client_socket = accept(sockid, (struct sockaddr *) &address, (socklen_t*)&addrlen);
		if (client_socket == -1) {
			cout << "client_socket open server failed" << endl;
			exit(1);
		}
		//notify main that we can continue the running
		if (!this->openedConn) {
			this->openedConn = true;
		}
		//if()
		//parse the data- we get float,float,float and need to put in the sys table, base on the XML data
		char buffer[2048];
		int valread = read(client_socket, buffer, 2048);
		string buf(buffer);
		//it is possible to get more than 1 list of vars so we seperate by \n
		while (buf.find("\n") != string::npos) {
			string msg = buf.substr(buf.find("\n"));
			int index = 0;
			cout <<"buf is"<< buf << endl;
			//interpet msg to update vals for sym table
			while (msg.find(",") != string::npos) {
				cout << "msg is "<<msg << endl;
				//if we saved a var with that path
				if (cp.getSymbolTable().containsPath(listofvars[index])) {
					cp.getSymbolTable().setValueFromPath(listofvars[index], stof(msg.substr(msg.find(","))));

				}
				//cut the string
				msg = msg.substr(msg.find(",")+1, string::npos);
				index++;
			}
			cout << "msg is " << msg << endl;
			//in the last float
			if (cp.getSymbolTable().containsPath(listofvars[index])) {
				cp.getSymbolTable().setValueFromPath(listofvars[index], stof(msg));
			}
			//cut the string
			buf= buf.substr(buf.find("\n")+1,string::npos);
			
		}
		//for the last buf
		int index = 0;
		cout << "buf is" << buf << endl;
		string msg = buf;
		//interpet msg to update vals for sym table
		while (msg.find(",") != string::npos) {
			cout << "msg is " << msg << endl;
			//if we saved a var with that path
			if (cp.getSymbolTable().containsPath(listofvars[index])) {
				cp.getSymbolTable().setValueFromPath(listofvars[index], stof(msg.substr(msg.find(","))));

			}
			//cut the string
			msg = msg.substr(msg.find(",") + 1, string::npos);
			index++;
		}
		cout << "msg is " << msg << endl;
		//in the last float
		if (cp.getSymbolTable().containsPath(listofvars[index])) {
			cp.getSymbolTable().setValueFromPath(listofvars[index], stof(msg));
		}
		//update the sym table of compiler
	}
	//close listening socket
	//close(sockid);
}

//creates a server that gets values
int openServerCommand::execute(Compiler cp,string s) {
	//block the main for only the first connection
	//std::thread thread1(this->openConnection,cp,s);
	std::thread thread1(&openServerCommand::openConnection,this,cp,s);
	//hold it until connection is made
	while (!this->openedConn) {

	}
	//detach the thread from the current function
	thread1.detach();
	openConnection(cp,s);
	//change later!
	return 1;

}

