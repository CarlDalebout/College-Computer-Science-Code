#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
class Server
{
    Server()
    {}
    Server(int port, int max_connection, int timeout_duration, std::string dir_name)
    :port_(port), max_connections_(max_connection), sockets_(new int[max_connection]) timeout_duration_(timeout_duration), dir_name_(dir_name)
    {
        for(int i = 0; i < )

        struct sockaar_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port_);
    }

    ~Server()
    {
        for (int i = 0; i < max_connections_; i++) 
        {
            close(server_fds[i]);
        }
    }

    int* sockets_;
    int  port_;
    int  connections_;
    int  max_connections_;
    int  timeout_duration_;
    std::string dir_name_;
};


#endif