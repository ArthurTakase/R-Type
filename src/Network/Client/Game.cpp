/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#include "Game.hpp"

#include <iostream>

#include "DrawableComponent.hpp"
#include "TransformComponent.hpp"

Game::Game(std::queue<GamePacket>& packets, std::mutex& mutex)
    : dataReceived_(packets)
    , mutexForPacket_(mutex)
{
    manager_ = std::make_unique<EntityManager>();
    lib_     = std::make_unique<Lib>();
}

void Game::run() noexcept
{
    lib_->getWindow().clear();
    {
        std::lock_guard<std::mutex> lock(mutexForPacket_);
        while (!dataReceived_.empty()) {
            auto& packet = dataReceived_.front();
            deserializeEntity(packet);
            dataReceived_.pop();
        }
    }
    for (auto& entity : manager_->getEntities()) {
        if (!entity->hasComponent<TransformComponent>() || !entity->hasComponent<DrawableComponent>()) { continue; }

        auto transform = entity->getComponent<TransformComponent>();
        auto drawable  = entity->getComponent<DrawableComponent>();

        if (drawable->getSprite() == nullptr) { continue; }

        drawable->getSprite()->setX(transform->getX());
        drawable->getSprite()->setY(transform->getY());
        lib_->getWindow().draw(drawable->getSprite(),
            drawable->getOffsetX(),
            drawable->getOffsetY(),
            drawable->getWidth(),
            drawable->getHeight());
    }
    lib_->getWindow().refresh();
}

Lib& Game::getLib() noexcept
{
    return *lib_;
}

void Game::addSprite(std::string path, int x, int y) noexcept
{
    sprites_.emplace_back(std::make_unique<Sprite>(path, x, y));
}

Sprite* Game::getLastSprite() noexcept
{
    return sprites_.back().get();
}

void Game::deserializeEntity(GamePacket packet) noexcept
{
    auto m_entity = manager_->getEntity(packet.id);

    if (m_entity == nullptr) {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(manager_->createId());

        auto transform =
            TransformComponent(packet.xpositive ? packet.x : -(packet.x), packet.ypositive ? packet.y : -(packet.y));
        transform.setScale(packet.scaleX, packet.scaleY);

        auto drawable = DrawableComponent(packet.offsetX, packet.offsetY, packet.width, packet.height, packet.idSprite);
        addSprite("assets/r-typesheet" + std::to_string(packet.idSprite) + ".gif", packet.x, packet.y);
        drawable.setSprite(getLastSprite());

        entity->addComponent(transform);
        entity->addComponent(drawable);

        manager_->addEntity(std::move(entity));
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
