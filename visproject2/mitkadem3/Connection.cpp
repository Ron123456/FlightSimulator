//
// Created by amitnir29 on 09/01/2020.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include "Connection.h"

using namespace std;
int Connection::openconnection(int port, string ip) {
    //the connection is not open yet
    openedConn = false;

    //create the socket
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		//error
		cerr << "couldnt create socket" << endl;
		return -1;
	}

	// stting the ip & port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
	ip = ip.substr(1, ip.length() - 2);
    //address.sin_addr.s_addr = inet_addr(ip.c_str());
	//address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(port);
    if(inet_pton(AF_INET, ip.c_str(), &address.sin_addr)<=0)
    {
        throw "\nInvalid address/ Address not supported";
    }

    //connect
    is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        cerr << "couldnt connect to host server"<<endl;
        return -2;
    }
    //the connection is open
    openedConn = true;
}

int Connection::closeconnection() {
    // if open then close
    if (is_connect != -1) {
        return close(client_socket);
    } else {
        return -1;
    }
}

int Connection::senddata(string path, float val) {
    //the data to send
    string data = path + " " + to_string(val);
    // if connected, send
    if (is_connect != -1) {
        return send(client_socket, data.c_str(), data.size(), 0);
    } else {
        return -1;
    }
}

void Connection::open(int port, string ip) {
    thread openconnthread(&Connection::openconnection,this,port,ip);
    // Get starting timepoint
    auto start = std::chrono::high_resolution_clock::now();
    //hold it until connection is made
    while (!this->openedConn) {
        //print every 10 secs
        if (std::chrono::duration_cast<std::chrono::seconds>
                    (std::chrono::high_resolution_clock::now() - start).count()>10) {
            //cout << "holding main thread- connection..." << endl;
            start = std::chrono::high_resolution_clock::now();
        }

    }

    //detach the thread from the current function
    openconnthread.detach();

	//cout << "detached connection" << endl;
}
