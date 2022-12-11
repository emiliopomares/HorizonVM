#include "comm.h"

Axioma::HorizonVM::Networking::Server::Server() 
{
    running = false;
}

Axioma::HorizonVM::Networking::Server::~Server() 
{

}

void Axioma::HorizonVM::Networking::Server::serverRun() 
{
    std::cout << "Starting thread";
    while(running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "One second has elapsed...";
    }
}

void Axioma::HorizonVM::Networking::Server::listen(uint8_t *buffer, int maxSize)
{
    running = true;
    std::cout << "Wanting to start thread...";
    std::thread t1([=] { serverRun(); });
}