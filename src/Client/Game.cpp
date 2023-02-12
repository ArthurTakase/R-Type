/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#include <Client/Game.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <iostream>

/**
 * It's a constructor for the Game class
 *
 * @param packets The queue of packets received
 * @param mutex The mutex used to protect the queue of packets
 */
Game::Game(std::queue<GamePacket>& packets, std::mutex& mutex)
    : dataReceived_(packets)
    , mutexForPacket_(mutex)
    , drawableSystem_(&manager_)
{
    drawableSystem_.setWindow(&lib_.getWindow());
}

/**
 * It clears the window, deserializes the packets received, and draws the entities
 */
void Game::run() noexcept
{
    {
        std::lock_guard<std::mutex> lock(mutexForPacket_);
        while (!dataReceived_.empty()) {
            auto& packet = dataReceived_.front();
            deserializeEntity(packet);
            dataReceived_.pop();
        }
    }
    drawableSystem_.run();
}

/**
 * This function returns a reference to the Lib object that is stored in the Game
 * object.
 *
 * @return A reference to the lib_ object.
 */
Lib& Game::getLib() noexcept
{
    return lib_;
}

/**
 * It deserializes a packet and creates an entity if it doesn't exist, or updates
 * it if it does
 *
 * @param packet the packet received from the server
 */
void Game::deserializeEntity(GamePacket packet) noexcept
{
    auto m_entity = manager_.getEntity(packet.id);

    if (m_entity == nullptr) {
        auto entity = manager_.newEntity();

        int  x         = packet.xpositive ? packet.x : -(packet.x);
        int  y         = packet.ypositive ? packet.y : -(packet.y);
        auto transform = TransformComponent(x, y);
        transform.setScale(packet.scaleX, packet.scaleY);

        auto drawable = DrawableComponent(packet.offsetX, packet.offsetY, packet.width, packet.height, packet.idSprite);
        drawable.getSprite().setSpritePath("assets/img/r-typesheet" + std::to_string(packet.idSprite) + ".gif");
        drawable.getSprite().setX(packet.x);
        drawable.getSprite().setY(packet.y);

        entity->addComponent(transform);
        entity->addComponent(drawable);
    } else {
        auto transform = m_entity->getComponent<TransformComponent>();
        auto drawable  = m_entity->getComponent<DrawableComponent>();

        transform->setX(packet.xpositive ? packet.x : -(packet.x));
        transform->setY(packet.ypositive ? packet.y : -(packet.y));
        transform->setScale(static_cast<float>(packet.scaleX / 10), static_cast<float>(packet.scaleY / 10));
        drawable->setOffsetX(packet.offsetX);
        drawable->setOffsetY(packet.offsetY);
        drawable->setWidth(packet.width);
        drawable->setHeight(packet.height);
        drawable->setTextureId(packet.idSprite);
    }
}
