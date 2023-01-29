#include <SFML/Network.hpp>
#include <iostream>

int main(void)
{
    sf::UdpSocket socket;
    socket.setBlocking(false);
    socket.bind(3001);
    unsigned short port = 3000;

    while (true) {
        // Send a message to the client
        std::string message;
        std::cout << "Enter message to send to client: ";
        std::getline(std::cin, message);
        socket.send(message.c_str(), message.size() + 1, "127.0.0.1", 3000);

        // Receive a message from the client
        char buffer[1024];
        std::size_t received = 0;
        sf::IpAddress sender;
        socket.receive(buffer, sizeof(buffer), received, sender, port);
        std::cout << "Client said: " << buffer << std::endl;
    }

    return 0;
}
