/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** Udp_Client.hpp
*/

#pragma once

#include <SFML/Network.hpp>

class Udp_Client {
  public:
    Udp_Client() {
        socket.setBlocking(true); // no needed to be asynchrone for client
        socket.bind(3000);
        serverip_   = "127.0.0.1";
        serverport_ = 4242;
    }
    ~Udp_Client() {}

    std::string receive() {
        char          buffer[1024];
        std::size_t   received = 0;
        sf::IpAddress sender;
        socket.receive(buffer, sizeof(buffer), received, sender, serverport_);
        return buffer;
    }

    bool send(std::string message) {
        return (socket.send(message.c_str(), message.size() + 1, serverip_, serverport_) == sf::Socket::Done) ? true : false;
    }
    sf::IpAddress  getServerIp() const noexcept { return serverip_; }
    void           setServerIp(const sf::IpAddress& new_ip) noexcept { serverip_ = new_ip; }
    unsigned short getServerPort() const noexcept { return serverport_; }
    unsigned short setPort(const unsigned short new_port) noexcept { return serverport_ = new_port; }

  private:
    sf::UdpSocket  socket;
    sf::IpAddress  serverip_;
    unsigned short serverport_;
};