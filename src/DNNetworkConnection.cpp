/**
 * @file DNNetworkConnection.cpp
 * @brief Network connection service
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNLogService.h"
#include "DNWindow.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>

#include "DNNetworkConnection.h"

using namespace std;




int DNNetworkConnection::startServer()
{
    DNWindow::getInstance().clearScreen();
    DNWindow::getInstance().drawHeader();
    
    

    /* create socket */
    if ((sockDesc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        DNLogService::sharedObject() << "ERROR => " << "Can not create socket!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Can not create socket!"));
    }

    /* bind socket to any addr and port 7777 */
    sockaddr_in localAddr;
    memset(& localAddr, 0, sizeof ( localAddr)); //clear it from garbage
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    localAddr.sin_port = htons(7777);

    if (bind(sockDesc, (sockaddr *) & localAddr, sizeof ( sockaddr_in)) < 0) {
        DNLogService::sharedObject() << "ERROR => " << "Can not bind!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Cannot bind to port"));
       
    }

    /* get local address */
    sockaddr_in addr;
    unsigned int addr_len = sizeof (addr);
    if (getsockname(sockDesc, (sockaddr *) & addr, (socklen_t *) & addr_len) < 0) {
        DNLogService::sharedObject() << "ERROR => " << "Unable to fetch local ip address!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Unable to fetch local IP address"));
    }
    DNLogService::sharedObject() << "INFO => " << "Started server on: " << inet_ntoa(addr.sin_addr) << ":7777" << "\n";
    DNWindow::getInstance().middleString(string("Server started on port 7777"), 5);
    DNWindow::getInstance().refreshDN();
    

    /* start listening */
    if (listen(sockDesc, 3) < 0) //3 is just in case.. one never know..
    {
        DNLogService::sharedObject() << "ERROR => " << "Set listening socket failed!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Set listening socket failed!"));
    }
    
    DNLogService::sharedObject() << "INFO => " << "Waiting for client to connect." << "\n";
    DNWindow::getInstance().middleString(string("Waiting for client to connect"), 6);
    DNWindow::getInstance().refreshDN();
    /* accept client */
    int clientSockDesc;
    if ((clientSockDesc = accept(sockDesc, NULL, 0)) < 0) {
        DNLogService::sharedObject() << "ERROR => " << "Accept failed!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Accept failed"));
                
    }

    DNLogService::sharedObject() << "INFO => " << "Client connected, starting game" << "\n";
    DNWindow::getInstance().middleString(string("Client connected, starting game"), 7);
    sleep(1);

    return clientSockDesc;


    //Game l_game (PLAYER_VS_PLAYER_NETWORK, clientSockDesc);
    //   createServerGame ( clientSockDesc );    
}

int DNNetworkConnection::connectToServer()
{
    /* get address from user */
    string remoteAddr;
    int port = 7777;
    DNLogService::sharedObject() << "INFO => " << "Enter remote address: ";
    DNWindow::getInstance().enterServerIPAdress(remoteAddr);

    if (remoteAddr.length() == 0) {
        DNLogService::sharedObject() << "ERROR => " << "Bad input! -- ip address sucked" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Empty ip address  -- exiting"));
    }

    if ((sockDesc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        DNLogService::sharedObject() << "ERROR => " << "Can not create socket!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Cannot create socket!!!"));
    }

    
    sockaddr_in addr;
    memset(&addr, 0, sizeof (addr));
    addr.sin_family = AF_INET;
    hostent * host;
    if ((host = gethostbyname(remoteAddr . c_str())) == NULL) {
        string fekalError("Cannot Resolve Hostname -- exiting !!!");
        DNWindow::getInstance().terminateWithErrorMessage(fekalError);
    }
    addr.sin_addr.s_addr = *((unsigned long *) host -> h_addr_list[0]);
    addr.sin_port = htons(port);

    DNWindow::getInstance().clearScreen();
    DNWindow::getInstance().drawHeader();
    DNWindow::getInstance().middleString(string("Connecting..."), 10);
    DNWindow::getInstance().refreshDN();
    sleep(2);
    
    
    if (connect(sockDesc, (sockaddr *) & addr, sizeof ( addr)) < 0) {
        DNLogService::sharedObject() << "ERROR => " << "Can not connect!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(string("Can not connect!"));
    }

    return sockDesc;


}



bool DNNetworkConnection::sendData(int socketDescriptor, string message)
{
    if (send(socketDescriptor, (void *) message . c_str(), message . size(), 0) < 0) {
        string fekalError("ERROR => Send failed!");
        DNLogService::sharedObject() << "ERROR => " << "Send failed!" << "\n";
        DNWindow::getInstance().terminateWithErrorMessage(fekalError);
        return false;
    }
    DNLogService::sharedObject() << "INFO => " << "This data sent ==> " << message << "\n";
    return true;
}



string DNNetworkConnection::receiveData(int socketDescriptor)
{
    char buffer[1024];
    /* cekame na data. navratova hodnota = pocet ziskanych bajtu */
    memset(buffer, 0, sizeof ( buffer));

    recv(socketDescriptor, buffer, sizeof ( buffer), 0);
    stringstream ss;
    ss << buffer;
    DNLogService::sharedObject() << "INFO => " << "This Data received" << ss.str() << "\n";
    return ss.str();
}

void DNNetworkConnection::closeConnection(int sock)
{
    close(sock);
}
