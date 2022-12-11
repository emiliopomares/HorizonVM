#include <iostream>
#include "./comm/comm.h"
//#include <boost/asio.hpp>

Axioma::HorizonVM::Networking::Server *server;

int main(int argc, char *argv[])
{
    server = new Axioma::HorizonVM::Networking::Server();
    server->listen(nullptr, 1024);
}
