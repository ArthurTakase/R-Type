/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#pragma once

#include <NetworkLib/ISocket.hpp>
#include <NetworkLib/SocketSelector.hpp>
#include <Server/RType.hpp>
#include <memory>
#include <thread>
#include <vector>

typedef struct Player {
    Address          address;
    std::vector<int> entities_id;
} Player;

/**
 * @brief Server class using UDP protocol
 *
 */
class Server
{
  public:
    Server() noexcept = delete;
    explicit Server(Address::Port port);

    Server(const Server& other) noexcept = delete;
    Server(Server&& other) noexcept      = default;
    ~Server() noexcept                   = default;

    Server& operator=(const Server& rhs) noexcept = delete;
    Server& operator=(Server&& rhs) noexcept      = default;

    void run();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    // attributes
    bool                                           looping_  = true;
    int                                            tickrate_ = 60;
    std::vector<Client>                            clients_  = {};
    std::unique_ptr<ISocket>                       socket_;
    std::unique_ptr<SocketSelector>                selector_;
    std::thread                                    gameThread_;
    std::thread                                    networkThread_;
    RType                                          gameInstance_;
    std::chrono::system_clock::time_point          end_;
    std::chrono::high_resolution_clock::time_point start_;
    std::vector<Player>                            players_;

    static constexpr int CLOSE_VALUE = 255;
    static constexpr int PACKET_SIZE = 13;

    // methods
    void                  receive();
    void                  send() noexcept;
    void                  sendToClient(Client& client, RawData blob);
    bool                  isKnownClient(Address address) const;
    void                  addClient(Address address) noexcept;
    void                  handleData(ReceivedInfos infos) noexcept;
    [[nodiscard]] RawData getDataFromQueue(Client& client) noexcept;

    // thread methods
    void communicate() noexcept;
    void gameLoop() noexcept;
};
