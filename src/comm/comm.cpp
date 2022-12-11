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
    std::cout << "Starting thread\n";
    std::cout.flush();
    while(running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "One second has elapsed...\n";
	std::cout.flush();
    }
}

void Axioma::HorizonVM::Networking::Server::listen(uint8_t *buffer, int maxSize)
{
    running = true;
    std::cout << "Wanting to start thread...\n";
    std::cout.flush();
    std::thread t1([this] { serverRun(); });
    t1.join();
}
