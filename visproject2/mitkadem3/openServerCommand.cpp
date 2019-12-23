#include "openServerCommand.h"
#include <sys/socket.h> 
//creates a server that gets values
int openServerCommand::execute(string s) {
	//get port somehow- depends on parser
	int port;
	int sockid = socket(AF_INET,SOCK_STREAM,0);
	if (sockid == -1) {
		cout << "error in openserver socket"<<endl;
		exit(1);
	}
	//open connection to server
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = "127.0.0.1"; //or INADDR_ANY
	address.sin_port = htons(port);
	if (bind(sockid,(struct sockaddr *) &address,sizeof(address)) == -1) {
		exit(1);
	}

	if (listen(sockid,5)==-1) {
		cout << "listening open server failed" << endl;
		exit(1);
	}
	//this is the flight simulator socket
	int clinet_socket = accept(sockid, (struct sockaddr *) &address,(socklen_t*)&address);
	if (client_socket == -1) {
		cout << "client_socket open server failed" << endl;
		exit(1);
	}
	//parse the data- we get float,float,float and need to put in the sys table, base on the XML data


	//close listening socket
	close(sockid);
}