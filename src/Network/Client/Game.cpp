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

Game::Game()
{
    manager_ = std::make_unique<EntityManager>();
    lib_     = std::make_unique<Lib>();
}

void Game::run() const noexcept
{
    lib_->getWindow().clear();

    for (auto& entity : manager_->getEntities()) {
        if (!entity->hasComponent<TransformComponent>() || !entity->hasComponent<DrawableComponent>()) { continue; }

        auto transform = entity->getComponent<TransformComponent>();
        auto drawable  = entity->getComponent<DrawableComponent>();

        if (drawable->getSprite() == nullptr) {
            std::cout << "Sprite is null" << std::endl;
            continue;
        }

        drawable->getSprite()->setX(transform->getX());
        drawable->getSprite()->setY(transform->getY());

        lib_->getWindow().draw(drawable->getSprite());
    }

    lib_->getWindow().refresh();
}

std::unique_ptr<EntityManager>& Game::getManager() noexcept
{
    return manager_;
}

std::unique_ptr<Lib>& Game::getLib() noexcept
{
    return lib_;
}

void Game::addSprite(std::string path, int x, int y) noexcept
{
    sprites_.emplace_back(std::make_unique<Sprite>(path, x, y));
}

Sprite* Game::getLastSprite() noexcept
{
    return sprites_.back().get();
}