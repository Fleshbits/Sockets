
// Protocol Library
#include "Protocol.h"

// Common Library Includes
#include "Exception.h"

// Boost Includes
#include <boost/asio.hpp>

// Standard Includes
#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace boost::asio::ip;
using namespace std;

enum
{
    max_length = 1024
};


int main(int argc, char * argv[])
{
    MadeUpProtocol::CommandMessage message;

    /* We aren't doing blocking socket
    try
    {
        if( argc != 3 )
        {
            std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
            return 1;
        }

        boost::asio::io_service ioService;

        // Resolve the hostname and port
        tcp::resolver           resolver(ioService);
        tcp::resolver::query    query(tcp::v4(), argv[1], argv[2]);
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket socket(ioService);
        socket.connect(*iterator);

        std::cout << "Enter message: ";
        char request[max_length];
        std::cin.getline(request, max_length);
        size_t request_length = strlen(request);

        boost::asio::write(socket, boost::asio::buffer(request, request_length));

        char reply[max_length];
        
        size_t reply_length = boost::asio::read(socket, boost::asio::buffer(reply, request_length));
        
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
    }
    catch(std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    */

    return 0;
}

