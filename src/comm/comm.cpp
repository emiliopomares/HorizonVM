#include "comm.h"
#include "../utils/network/networkUtils.h"
#ifndef BOOST
  #include <boost/asio.hpp>
  #define BOOST
#endif
#include <boost/array.hpp>

Axioma::HorizonVM::Networking::Server::Server(std::string _ipAddress) 
{
    running = true;
    ipAddress = _ipAddress;
}

Axioma::HorizonVM::Networking::Server::~Server() 
{

}

/**
 * Processes a received UDP message.
 *
 * Will do nothing if the message is received by the sender machine
 *
 * @param message The received message.
 * @param sourceAddress The source ip address of the message.
 */
void Axioma::HorizonVM::Networking::Server::processMessage(uint8_t *data, int length, std::string sourceAddress)
{
    if(sourceAddress == ipAddress)
    {
        return;
    }

    std::cout << "  Acknowledged node at " << sourceAddress << "\n";
}

void Axioma::HorizonVM::Networking::Server::serverRun() 
{
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket socket(io_service);
    socket.open(boost::asio::ip::udp::v4());
    boost::asio::socket_base::broadcast option(true);
    socket.set_option(option);
    socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::address_v4::any(),27183));
    boost::asio::ip::udp::endpoint sender_endpoint;

    boost::array<uint8_t, 4096> receive_buffer;
    while(running)
    {
        std::size_t bytes_transferred = socket.receive_from(boost::asio::buffer(receive_buffer), sender_endpoint);
        std::string message = "";
        std::string sourceAddress = sender_endpoint.address().to_string();
        processMessage(receive_buffer.c_array(), bytes_transferred, sourceAddress);
        //std::cout << "   .... yes ?? " << bytes_transferred << "  " << sender_endpoint.address() << "\n";
        //std::cout.flush();
    }
}

void Axioma::HorizonVM::Networking::Server::broadcastRun() 
{
    std::cout << "Starting thread broadcastRun\n";
    std::cout.flush();

    boost::system::error_code error;
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket socket(io_service);

    socket.open(boost::asio::ip::udp::v4(), error);
    if (!error)
    {
        std::cout << "    Enter here\n";
        std::cout.flush();
        socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
        socket.set_option(boost::asio::socket_base::broadcast(true));

        boost::asio::ip::udp::endpoint senderEndpoint(boost::asio::ip::address_v4::broadcast(), 27183);

        std::string strToTransmit = "{\"magic\":\"0xdeadbeef\"}";
        int strLength = strToTransmit.length();

        while(running)
        {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << " --- BROADCASTING --- \n";
            std::cout.flush();
            socket.send_to(boost::asio::buffer(strToTransmit, strLength), senderEndpoint);
        }
        socket.close(error);
    }
    else {
        std::cout << "Error " << error << "\n";
        std::cout.flush();
    }
}

std::thread Axioma::HorizonVM::Networking::Server::startBroadcasting(std::string ip)
{
    std::thread thread([this] { broadcastRun(); });
    return thread;
}

std::thread Axioma::HorizonVM::Networking::Server::listenBroadcast(uint8_t *buffer, int maxSize)
{
    std::thread thread([this] { serverRun(); });
    return thread;
}
