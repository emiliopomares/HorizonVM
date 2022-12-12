#include "networkUtils.h"
#include <iostream>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

std::string Axioma::HorizonVM::Networking::NetworkUtils::getipv4()
{
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(boost::asio::ip::host_name(), "");
    tcp::resolver::iterator iter = resolver.resolve(query);
    tcp::resolver::iterator end; // End marker.
    
    tcp::endpoint ep = *iter++;
    return ep.address().to_string();
}