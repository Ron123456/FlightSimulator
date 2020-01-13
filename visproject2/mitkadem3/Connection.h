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
    //connection open or close?
    bool openedConn = false;
    //private method to run in thread
    int openconnection(int port, string ip);
    //the client socket
    volatile int client_socket;
    // the is connect variable
    volatile int is_connect;
public:
    //send data function
    int senddata(string path, float val);
    //open is just openning openconnection in a different thread
    void open(int port, string ip);
    //close the connection
    int closeconnection();
};


#endif //FLIGHTSIMULATOR_CONNECTION_H
