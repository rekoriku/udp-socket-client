#include "SocketClient.h"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

SocketClient::SocketClient(int port)
{
    server.sin_family = AF_INET; // ipv4 address
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
}

void SocketClient::start()
{
    std::cout << "Connecting to server \n";
    bind(sock, (sockaddr *)&server, sizeof(server));
}

void SocketClient::listen()
{
    while (!end)
    {
        sendMsg();
    }
}

void SocketClient::sendMsg()
{
    std::cout << "Send message: ";
    std::cin.getline(buffer, sizeof(buffer));
    sendto(sock, buffer, strlen(buffer), 0, (sockaddr *)&server, addrlen);
    if (buffer[0] != 0)
    {
        count = recvfrom(sock, readbuffer, sizeof(readbuffer) - 1, 0, (sockaddr *)&server, &addrlen);

        if (count > 0)
        {
            std::cout << "Number of characters in the message is " << readbuffer << std::endl;
        }
    }
    else
    {
        stop();
    }
}

void SocketClient::stop()
{
    std::cout << "Shutting down \n";
    close(sock);
    end = true;
}