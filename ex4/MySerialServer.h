//
// Created by amitnir29 on 17/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "interfaces.h"
using namespace server_side;
class MySerialServer : public Server {
public:
    int open(int port) override;

    int close() override;

};


#endif //EX4_MYSERIALSERVER_H
