#include "SocketClient.h"
int main(int argc, char *argv[])
{
    SocketClient* client = new SocketClient(5000);

    client->start();
    client->listen();
}