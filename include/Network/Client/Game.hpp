/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#pragma once

#include <Entity/EntityManager.hpp>
#include <Lib/Lib.hpp>
#include <queue>

/**
 * @brief This struct is used to process the data received from the server.
 *
 */
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

/**
 * @brief This class is used to create a game instance in the client.
 *
 */
class Game
{
  public:
    Game(std::queue<GamePacket>& packets, std::mutex& mutex);
    ~Game() noexcept                 = default;
    Game(const Game& other) noexcept = delete;
    Game(Game&& other) noexcept      = delete;

    Game& operator=(const Game& rhs) noexcept = delete;
    Game& operator=(Game&& rhs) noexcept      = delete;

    void    run() noexcept;
    Lib&    getLib() noexcept;
    void    addSprite(std::string path, int x, int y) noexcept;
    Sprite* getLastSprite() noexcept;

  private:
    EntityManager                        manager_;
    Lib                                  lib_;
    std::vector<std::unique_ptr<Sprite>> sprites_ = {};
    std::queue<GamePacket>&              dataReceived_;
    std::mutex&                          mutexForPacket_;

    void deserializeEntity(GamePacket packet) noexcept;
};