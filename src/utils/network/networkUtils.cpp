#include "networkUtils.h"
#include <iostream>
#ifndef BOOST
  #include <boost/asio.hpp>
  #define BOOST
#endif
using boost::asio::ip::tcp;

std::string Axioma::HorizonVM::Networking::NetworkUtils::getipv4()
{
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(boost::asio::ip::host_name(), "");
    tcp::resolver::iterator iter = resolver.resolve(query);
    tcp::resolver::iterator end; // End marker.
 
    std::string result;
	int counter = 0; 
    while (iter != end)
    {
       boost::asio::ip::tcp::endpoint endpoint = *iter++;
       std::cout << endpoint << std::endl;
       std::cout << counter++;
       std::cout.flush(); 
       result = endpoint.address().to_string(); 
    } 

    std::cout << boost::asio::ip::address_v4::loopback() << "\n"; 
    
    return result;
}
