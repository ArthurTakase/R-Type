/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#pragma once

#include <Client/Game.hpp>
#include <NetworkLib/ISocket.hpp>
#include <NetworkLib/SocketSelector.hpp>
#include <Serializer/Deserializer.hpp>
#include <memory>
#include <thread>

/**
 * @brief Client class using UDP protocol
 *
 */
class UdpClient
{
  public:
    UdpClient() noexcept = delete;
    explicit UdpClient(Address serverAddress, Address::Port clientPort);

    UdpClient(const UdpClient& other) noexcept = delete;
    UdpClient(UdpClient&& other) noexcept      = delete;
    ~UdpClient() noexcept                      = default;

    UdpClient& operator=(const UdpClient& rhs) noexcept = delete;
    UdpClient& operator=(UdpClient&& rhs) noexcept      = delete;

    void run();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    // attributes
    bool                            looping_ = true;
    Address                         serverAddress_;
    int                             tickrate_ = 60;
    std::unique_ptr<ISocket>        socket_;
    std::unique_ptr<SocketSelector> selector_;
    std::thread                     gameThread_;
    std::thread                     networkThread_;
    std::queue<RawData>             dataToSend_     = {};
    std::queue<GamePacket>          dataReceived_   = {};
    std::mutex                      mutexForPacket_ = {};
    Game                            game_;

    static constexpr int CLOSE_VALUE = 255;
    static constexpr int PACKET_SIZE = 15;

    // methods
    void    receive();
    void    send();
    void    handleData(ReceivedInfos infos) noexcept;
    RawData getDataFromQueue() noexcept;

    // thread methods
    void communicate() noexcept;
    void gameLoop() noexcept;
};
