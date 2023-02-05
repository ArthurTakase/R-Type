/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#include "UdpClient.hpp"

#include <iostream>

#include "Deserializer.hpp"
#include "DrawableComponent.hpp"
#include "Error.hpp"
#include "SocketFactory.hpp"
#include "SocketSelectorFactory.hpp"

#define CLOSE_VALUE 65535

[[nodiscard]] UdpClient::UdpClient(Address serverAddress, Address::Port clientPort)
    : serverAddress_(serverAddress)
    , socket_(SocketFactory::createSocket(clientPort))
    , selector_(SocketSelectorFactory::createSocketSelector(socket_->getSocketFd() + 1))
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });

    std::cout << "UdpClient created" << std::endl;

    loadSprites();
}

void UdpClient::stop() noexcept
{
    looping_ = false;
}

void UdpClient::reset() noexcept
{
    looping_ = true;
}

void UdpClient::run()
{
    gameThread_.join();
    networkThread_.join();
}

void UdpClient::communicate() noexcept
{
    // TODO : send a connection request to the server
    RawData data = { 12 };
    dataToSend_.push(data);

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

void UdpClient::gameLoop() noexcept
{
    auto& lib = game_.getLib();
    lib->getWindow().open(600, 400, "Client RTYPE");

    while (looping_) {
        auto input = lib->getWindow().getKeyPressed();
        if (input == 255 || input == 36) {
            looping_ = false;
            break;
        }
        if (input != 0) { dataToSend_.push({ (uint16_t)input }); }
        game_.run();
    }

    dataToSend_.push({ CLOSE_VALUE });
    lib->getWindow().close();
}

void UdpClient::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        handleData(infoReceived);
    } catch (const NetworkExecError& e) {
        std::cerr << e.what() << std::endl;
    }
}

void UdpClient::send()
{
    if (dataToSend_.size() != 0) {
        auto blob = getDataFromQueue();
        try {
            socket_->send(blob.data(), blob.size(), serverAddress_);
        } catch (const NetworkExecError& e) {
            std::cerr << e.what() << std::endl;
            dataToSend_.push(blob);
        }
    }
}

RawData UdpClient::getDataFromQueue() noexcept
{
    RawData blob = dataToSend_.front();
    dataToSend_.pop();
    return (blob);
}

void UdpClient::handleData(ReceivedInfos infos) noexcept
{
    if (infos.data.size() == 0) return;
    if (infos.data.size() % 10 == 0) {
        for (int i = 0; i < infos.data.size(); i += 10) {
            deserializeEntity(infos.data[i],
                infos.data[i + 1],
                infos.data[i + 2],
                infos.data[i + 3],
                infos.data[i + 4],
                infos.data[i + 5],
                infos.data[i + 6],
                infos.data[i + 7],
                infos.data[i + 8],
                infos.data[i + 9]);
        }
    }
    infos.data.clear();
}

void UdpClient::deserializeEntity(int x,
    int                               y,
    int                               idSprite,
    int                               width,
    int                               height,
    int                               scaleX,
    int                               scaleY,
    int                               offsetX,
    int                               offsetY,
    int                               id) noexcept
{
    std::cout << "Deserialize entity" << std::endl;
    auto& manager  = game_.getManager();
    auto  m_entity = manager->getEntity(id);

    if (m_entity == nullptr) {
        std::cout << "Create entity" << std::endl;
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(manager->createId());

        auto transform = TransformComponent(x, y);
        transform.setScale(scaleX, scaleY);

        auto drawable = DrawableComponent(offsetX, offsetY, width, height, idSprite);
        game_.addSprite(sprites_[idSprite], x, y);
        drawable.setSprite(game_.getLastSprite());

        entity->addComponent(transform);
        entity->addComponent(drawable);

        manager->addEntity(entity);
    } else {
        std::cout << "Update entity" << std::endl;
        auto transform = m_entity->getComponent<TransformComponent>();
        auto drawable  = m_entity->getComponent<DrawableComponent>();

        transform->setX(x);
        transform->setY(y);
        transform->setScale((float)scaleX / 10, (float)scaleY / 10);
        drawable->setOffsetX(offsetX);
        drawable->setOffsetY(offsetY);
        drawable->setWidth(width);
        drawable->setHeight(height);
        drawable->setTextureId(idSprite);
    }
}

void UdpClient::loadSprites() noexcept
{
    for (int i = 0; i < 43; i++) { sprites_.emplace_back("assets/r-typesheet" + std::to_string(i + 1) + ".gif"); }
}