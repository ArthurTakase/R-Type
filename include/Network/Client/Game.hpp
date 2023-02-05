/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#pragma once

#include <queue>

#include "EntityManager.hpp"
#include "Lib.hpp"

struct GamePacket {
    int x;
    int xpositive;
    int y;
    int ypositive;
    int idSprite;
    int width;
    int height;
    int scaleX;
    int scaleY;
    int offsetX;
    int offsetY;
    int id;
};

class Game
{
  public:
    Game(std::queue<GamePacket>& packets, std::mutex& mutex);
    ~Game() noexcept                 = default;
    Game(const Game& other) noexcept = delete;
    Game(Game&& other) noexcept      = delete;

    Game& operator=(const Game& rhs) noexcept = delete;
    Game& operator=(Game&& rhs) noexcept      = delete;

    void           run() noexcept;
    Lib&           getLib() noexcept;
    void           addSprite(std::string path, int x, int y) noexcept;
    Sprite*        getLastSprite() noexcept;

  private:
    std::unique_ptr<EntityManager>       manager_;
    std::unique_ptr<Lib>                 lib_;
    std::vector<std::unique_ptr<Sprite>> sprites_ = {};
    std::queue<GamePacket>&              dataReceived_;
    std::mutex&                          mutexForPacket_;

    void deserializeEntity(GamePacket packet) noexcept;
};