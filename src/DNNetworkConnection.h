/**
 * @file DNNetworkConnection.h
 * @brief Network connection service
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */


#include <iostream>          // for cin, cout, cerr
#include <sys/types.h>       // for data types
#include <sys/socket.h>      // for socket(), connect(), send(), and recv()
#include <netdb.h>           // for gethostbyname()
#include <arpa/inet.h>       // for inet_addr()
#include <unistd.h>          // for close()
#include <cstring>           // for memset
#include <cstdlib>           // for atoi
#include <netinet/in.h>      // for sockaddr_in
#include <string>            // for string
#include <sstream>            // for string


#ifndef DNNETWORKCONNECTION_H
#define	DNNETWORKCONNECTION_H
using namespace std;
class DNNetworkConnection {
public:
    /**
     * Getter for instance
     * @return instance
     */
    static DNNetworkConnection& getInstance()
    {
        static DNNetworkConnection instance;
        return instance;
    }
    /**
     * Starts server 
     * @return socket descriptor
     */
    int startServer();
    /**
     * Connects to server
     * @return socket descriptor
     */
    int connectToServer();
    /**
     * Send data ovet TCP socket connection
     * @param socketDescriptor where to send
     * @param message what to send
     * @return success/failure
     */
    bool sendData(int socketDescriptor, string message);
    /**
     * Closses connection for socket descriptor
     * @param sock socket descriptor
     */
    void closeConnection(int sock);
    /**
     * Recieves data over TCP socket
     * @param socketDescriptor 
     * @return data
     */
    string receiveData(int socketDescriptor);

    
private:
    /**
     * Constructor
     */
    DNNetworkConnection(){};
    /**
     * Implicit copy contructor
     * @param 
     */
    DNNetworkConnection(DNNetworkConnection const&);
    /**
     * Operator =
     * @param righ hand side 
     */
    void operator=(DNNetworkConnection const&);
    int sockDesc;
};

#endif	/* DNNETWORKCONNECTION_H */

