#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    int port = 8080;
    if (argc > 1)
    {
        port = std::atoi(argv[1]);
    }
    try
    {
        boost::asio::io_context io;

        tcp::acceptor acceptor(
            io,
            tcp::endpoint(tcp::v4(), port)
        );

        std::cout << "Server started on port " << port << "...\n";

        while (true)
        {
            tcp::socket socket(acceptor.accept());

            boost::asio::streambuf buffer;
            boost::asio::read_until(socket, buffer, '\n');

            std::istream input(&buffer);
            std::string request;
            std::getline(input, request);

            std::cout << "Received: " << request << std::endl;

            std::string name = "Unknown";
            constexpr std::string prefix = "Hello, Server, I'm ";

            if (request.starts_with(prefix))
            {
                name = request.substr(prefix.size());
            }

            std::string response = "Hello, " + name + "\n";

            boost::asio::write(
                socket,
                boost::asio::buffer(response)
            );
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Server error: " << e.what() << std::endl;
    }
    return 0;
}
