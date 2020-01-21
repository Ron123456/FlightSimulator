//
// Created by amitnir29 on 17/01/2020.
//

#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string>
int MyTestClientHandler::handleClient(int socket){
	char buffer[1024];
	//read the data
	while (strcmp(buffer, "end") != 0) {
		int valread = read(socket, buffer, 1024);

		//if has sol, return it
		if (this->cm->hasSolution(buffer)) {
			//Solution sol = this->cm->getSolution(buffer);
			std::string str = this->cm->getSolution(buffer);
			//std::string str = Solution::toString();
			send(socket, str, strlen(str.c_str()), 0);
		}
		//else, calc solve.solve(input), cache it and return output
		else {
			std::string str = this->s->solve(buffer);
			this->cm->setSolution(buffer, str);
			//std::string str = Solution::toString();
			send(socket, str, strlen(str.c_str()), 0);
		}
	}
};