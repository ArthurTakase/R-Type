#include <SFML/Network.hpp>
#include <iostream>

int main(void)
{
    sf::UdpSocket socket;
    socket.setBlocking(false); // Asynchrone client
    socket.bind(3000);
    unsigned short port = 3001; // 4242

    /* À FIX
    sf::IpAddress sender;
    IpAddress sf::IpAddress::getLocalAddress()
    */

    while (true) {
        // Receive a message from the server
        char buffer[1024];
        std::size_t received = 0;
        sf::IpAddress sender;
        socket.receive(buffer, sizeof(buffer), received, sender, port);
        std::cout << "Server said: " << buffer << std::endl;

        // Send a message to the server
        std::string message;
        std::cout << "Enter message to send to server: ";
        std::getline(std::cin, message);
        socket.send(message.c_str(), message.size() + 1, "127.0.0.1", port);
    }

    return 0;
}
