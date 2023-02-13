/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include <ECS/Components/InputComponent.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/ISocket.hpp>
#include <NetworkLib/SocketFactory.hpp>
#include <NetworkLib/SocketSelectorFactory.hpp>
#include <Server/Server.hpp>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <locale>

[[nodiscard]] Server::Server(Address::Port port)
    : socket_(SocketFactory::createSocket(port))
    , selector_(SocketSelectorFactory::createSocketSelector())
{
    selector_->add(*socket_, true, true, false);
    end_   = std::chrono::system_clock::now();
    start_ = std::chrono::high_resolution_clock::now();

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
    gameInstance_.init();

    while (looping_) {
        end_ = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count() >= tickrate_) {
            start_ = {std::chrono::high_resolution_clock::now()};

            if (clients_.size() == 0 && gameInstance_.getManager().getEntities().size() == 0) {
                stop();
            } else {
                auto&   entities = gameInstance_.getManager().getEntities();
                RawData dataToSend;
                dataToSend.reserve(entities.size() * 12);
                for (auto& entity : entities) {
                    if (!entity->hasComponents<DrawableComponent, TransformComponent>()) { continue; }

                    auto drawable  = entity->getComponent<DrawableComponent>();
                    auto transform = entity->getComponent<TransformComponent>();
                    dataToSend.emplace_back(transform->getX() > 0 ? transform->getX() : -transform->getX());
                    dataToSend.emplace_back(transform->getX() > 0 ? 1 : 0);
                    dataToSend.emplace_back(transform->getY() > 0 ? transform->getY() : -transform->getY());
                    dataToSend.emplace_back(transform->getY() > 0 ? 1 : 0);
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
                for (auto& client : clients_) { client.dataToSend.push(dataToSend); }

                gameInstance_.run();
            }
        }
    }
}

bool Server::isKnownClient(Address address) const
{
    auto iterator = std::find_if(
        clients_.begin(), clients_.end(), [&address](const Client& client) { return (address == client.address); });
    return (iterator != clients_.end());
}

void Server::addClient(Address address) noexcept
{
    Client client{.address = address};
    clients_.push_back(client);
}

void Server::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        if (!isKnownClient(infoReceived.address)) {
            addClient(infoReceived.address);
            Player player = {.address = infoReceived.address, .entities_id = {gameInstance_.createPlayer(20, 50)}};
            players_.emplace_back(player);
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
    if (infos.data.size() == 0) { return; }

    if (infos.data[0] == CLOSE_VALUE) {
        auto iterator = std::find_if(clients_.begin(), clients_.end(), [&infos](const Client& client) {
            return (infos.address == client.address);
        });
        if (iterator != clients_.end()) {
            clients_.erase(iterator);
            // TODO: remove player entity in game instance
            //  gameInstance_.getManager().removePlayer();
        }
    }

    for (auto& player : players_) {
        if (player.address != infos.address) continue;
        for (auto& ent : player.entities_id) {
            auto entity = gameInstance_.getManager().getEntity(ent);
            if (!entity->hasComponent<InputComponent>()) continue;
            auto input = entity->getComponent<InputComponent>();
            input->addInput(infos.data[0]);
        }
    }

    infos.data.clear();
}
