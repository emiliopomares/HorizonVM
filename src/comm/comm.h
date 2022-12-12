#include <string>
#include <iostream>
#include <thread>
#include <chrono>

namespace Axioma 
{
    namespace HorizonVM 
    {
        enum NodeStatus
        {
            online, offline, unknown
        };

        enum OperationStatus
        {
            success, failure
        };

        class NodeIdentification
        {
            std::string ipv4;
            std::string ipv6;
            NodeStatus status;
            std::string name;
        };

        namespace Networking 
        {
            class Server
            {
                private:
                    bool running;
                    std::string ipAddress;
                    std::thread *thread;
                    void serverRun();
                    void broadcastRun();
                    void processMessage(uint8_t *data, int length, std::string sourceAddress);
                public:
                    Server(std::string _ipAddress);
                    ~Server();
                    OperationStatus initialize(std::string bindAddress, std::string port);
                    OperationStatus broadcast(uint8_t * buffer, int size);
                    std::thread startBroadcasting(std::string ip);
                    std::thread listenBroadcast(uint8_t *buffer, int maxSize);
            };

            class Client
            {
                public:
                    OperationStatus connect(std::string address, std::string port="31416");
            };
        }
    }
}