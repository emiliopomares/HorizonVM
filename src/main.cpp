#include <iostream>
#include "./comm/comm.h"
#include "./utils/network/networkUtils.h"
#include <boost/asio.hpp>

Axioma::HorizonVM::Networking::Server *server;

int main(int argc, char *argv[])
{
    std::string ipv4 = Axioma::HorizonVM::Networking::NetworkUtils::getipv4();
    server = new Axioma::HorizonVM::Networking::Server(ipv4);
    std::thread broadcastThread = server->startBroadcasting(ipv4);
    std::thread serverThread = server->listenBroadcast(nullptr, 1024);
    serverThread.join();
    broadcastThread.join();
}
