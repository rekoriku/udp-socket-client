#include <netinet/in.h>
#include <string>

class SocketClient
{
public:
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in server;

    int count;
    bool end = false;

    char buffer[100];
    char readbuffer[100];
    socklen_t addrlen = sizeof(sockaddr_in);

    SocketClient(int);
    void start();
    void listen();
    void sendMsg();
    void stop();
};