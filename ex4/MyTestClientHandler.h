//
// Created by amitnir29 on 17/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "interfaces.h"
#include <string>
#include "FileCacheManager.h"
class MyTestClientHandler : public client_handler::ClientHandler {
	problem_solving::Solver < std::string, std::string> *s;
	FileCacheManager<std::string>* cm;
public:
	MyTestClientHandler(problem_solving::Solver<std::string, std::string>* solver,
		FileCacheManager<std::string>* cache) : s(solver), cm(cache) {};
	int handleClient(int socket) override;
};


#endif //EX4_MYTESTCLIENTHANDLER_H
