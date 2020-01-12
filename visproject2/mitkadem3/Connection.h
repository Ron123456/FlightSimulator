//
// Created by amitnir29 on 09/01/2020.
//

#ifndef FLIGHTSIMULATOR_CONNECTION_H
#define FLIGHTSIMULATOR_CONNECTION_H


#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "Command.h"

using namespace std;
class Connection{
    bool openedConn = false;
    int openconnection(int port, string ip);
    volatile int client_socket;
    volatile int is_connect;
public:
    int senddata(string path, float val);
    //open is just openning openconnection in a different thread
    void open(int port, string ip);
    int closeconnection();
};


#endif //FLIGHTSIMULATOR_CONNECTION_H
