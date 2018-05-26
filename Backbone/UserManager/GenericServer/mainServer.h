//
// Created by eduardo on 04/05/18.
//

#ifndef ODDSERVER_MAINSERVER_H
#define ODDSERVER_MAINSERVER_H

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include "string"
#include "../DataBaseManager.h"

using string = std::string;

class mainServer {
public:
    mainServer(int port);

    short SocketCreate(void);
    int BindCreatedSocket(int hSocket);
    int runServer();

private:
        int port;
        DataBaseManager* SERVER = new DataBaseManager();

};


#endif //ODDSERVER_MAINSERVER_H
