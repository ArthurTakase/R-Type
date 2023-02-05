/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#pragma once

#include "EntityManager.hpp"
#include "Lib.hpp"

class Game
{
  public:
    Game();
    ~Game() noexcept                 = default;
    Game(const Game& other) noexcept = delete;
    Game(Game&& other) noexcept      = delete;

    Game& operator=(const Game& rhs) noexcept = delete;
    Game& operator=(Game&& rhs) noexcept      = delete;

    void                            run() const noexcept;
    std::unique_ptr<EntityManager>& getManager() noexcept;
    std::unique_ptr<Lib>&           getLib() noexcept;
    void                            addSprite(std::string path, int x, int y) noexcept;
    Sprite*                         getLastSprite() noexcept;

  private:
    std::unique_ptr<EntityManager>       manager_;
    std::unique_ptr<Lib>                 lib_;
    std::vector<std::unique_ptr<Sprite>> sprites_ = {};
};