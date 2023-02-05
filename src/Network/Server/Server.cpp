/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

#include <algorithm>
#include <iostream>

#include "Error.hpp"
#include "SocketFactory.hpp"
#include "SocketSelectorFactory.hpp"

[[nodiscard]] Server::Server(Address::Port port)
    : socket_(SocketFactory::createSocket(port))
    , selector_(SocketSelectorFactory::createSocketSelector(socket_->getSocketFd() + 1))
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

void Server::stop() noexcept
{
    looping_ = false;
    gameInstance_.stop();
}

void Server::reset() noexcept
{
    looping_ = true;
}

void Server::run()
{
    gameThread_.join();
    networkThread_.join();
}

void Server::communicate() noexcept
{
    while (looping_) {
        try {
            selector_->select(true, true, false);
        } catch (const NetworkExecError& message) {
            std::cerr << message.what() << std::endl;
        }
        if (selector_->isSet(*socket_, SocketSelector::Operation::READ)) { receive(); }
        if (selector_->isSet(*socket_, SocketSelector::Operation::WRITE)) { send(); }
    }
}

void Server::gameLoop() noexcept
{
    // TODO : insert game loop
    std::cout << "game loop start" << std::endl;

    gameInstance_.getManager()->createBackground(0);
    gameInstance_.getManager()->createBackground(600);
    // gameInstance_.getManager()->createPlayer();
    // gameInstance_.getManager()->createEnemy();
    // gameInstance_.getManager()->createEnemy();
    // gameInstance_.getManager()->createEnemy();

    while (looping_) {
        if (looping_ == false && clients_.size() == 0) {
            // TODO: changer la condition pour qu'une instruction envoyée par le client ou le jeu me dise quand la
            // window est fermée
            stop();
        } else {
            auto&   entities = gameInstance_.getManager()->getEntities();
            RawData dataToSend;
            for (auto& entity : entities) {
                if (!entity->hasComponents<DrawableComponent, TransformComponent>()) { continue; }

                auto drawable  = entity->getComponent<DrawableComponent>();
                auto transform = entity->getComponent<TransformComponent>();
                dataToSend.emplace_back(transform->getX());
                dataToSend.emplace_back(transform->getY());
                dataToSend.emplace_back(drawable->getTextureId());
                dataToSend.emplace_back(drawable->getWidth());
                dataToSend.emplace_back(drawable->getHeight());
                dataToSend.emplace_back(transform->getScaleX() * 10);
                dataToSend.emplace_back(transform->getScaleY() * 10);
                dataToSend.emplace_back(drawable->getOffsetX());
                dataToSend.emplace_back(drawable->getOffsetY());
                dataToSend.emplace_back(entity->getId());
            }

            if (dataToSend.size() == 0) { dataToSend.emplace_back(CLOSE_VALUE); }
            std::cout << "";

            for (auto& client : clients_) { client.dataToSend.push(dataToSend); }

            gameInstance_.run();
        }
        // TODO: reset de l'instance de jeu dans le cas ou on veut juste recommencer une partie // une partie (reset le
        // jeu)
    }
    std::cout << "game loop end" << std::endl;
}

bool Server::isKnownClient(Address address) const
{
    auto iterator = std::find_if(
        clients_.begin(), clients_.end(), [&address](const Client& client) { return (address == client.address); });
    return (iterator != clients_.end());
}

void Server::addClient(Address address) noexcept
{
    Client client{ .address = address };
    clients_.push_back(client);
}

void Server::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        if (!isKnownClient(infoReceived.address)) {
            std::cout << "new client" << std::endl;
            addClient(infoReceived.address);
        }
        handleData(infoReceived);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Server::send() noexcept
{
    for (auto& client : clients_) {
        if (client.dataToSend.size() != 0) { sendToClient(client, getDataFromQueue(client)); }
    }
}

void Server::sendToClient(Client& client, RawData blob) // blob : binary large object
{
    try {
        socket_->send(blob.data(), blob.size(), client.address);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
        client.dataToSend.push(blob);
    }
}

RawData Server::getDataFromQueue(Client& client) noexcept
{
    RawData blob = client.dataToSend.front();
    client.dataToSend.pop();
    return (blob);
}

void Server::handleData(ReceivedInfos infos) noexcept
{
    for (auto& data : infos.data) { std::cout << (int)data << " "; }
    std::cout << std::endl;

    if (infos.data.size() == 0) { return; }

    if (infos.data[0] == CLOSE_VALUE) { std::cout << "CLIENT DISCONNECT" << std::endl; }

    auto& behavior = gameInstance_.getBehaviorSystem();
    behavior->setKey(infos.data[0]);
    infos.data.clear();
}
