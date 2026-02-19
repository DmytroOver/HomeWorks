#include <boost/asio.hpp>
#include <iostream>
#include <string>


using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    std::string_view host = "127.0.0.1";
    std::string_view port = "8080";
    if (argc > 1)
    {
        host = argv[1];
        if (argc > 2)
        {
            port = argv[2];
        }
    }

    std::string name = "Unknown";
    std::cout << "What is your name? ";
    std::cin >> name;

    try
    {
        boost::asio::io_context io;

        tcp::socket socket(io);
        tcp::resolver resolver(io);

        boost::asio::connect(
            socket,
            resolver.resolve(host, port)
        );

        std::string message = "Hello, Server, I'm " + name + "\n";

        boost::asio::write(
            socket,
            boost::asio::buffer(message)
        );

        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, '\n');

        std::istream input(&buffer);
        std::string response;
        std::getline(input, response);

        std::cout << "Server response: " << response << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
}
