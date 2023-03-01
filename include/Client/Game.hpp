/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/DrawableSystem.hpp>
#include <ECS/Systems/MusicSystem.hpp>
#include <ECS/Systems/SoundSystem.hpp>
#include <Lib/Lib.hpp>
#include <Serializer/BitSize.hpp>
#include <queue>

/**
 * @brief This class is used to create a game instance in the client.
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

    void run() noexcept;
    Lib& getLib() noexcept;

    int            createSound(const std::string& path) noexcept;
    EntityManager& getManager() noexcept;

  private:
    EntityManager           manager_;
    Lib                     lib_;
    DrawableSystem          drawableSystem_;
    DestroyableSystem       destroyableSystem_;
    SoundSystem             soundSystem_;
    MusicSystem             musicSystem_;
    std::queue<GamePacket>& dataReceived_;
    std::mutex&             mutexForPacket_;

    void updateOrCreateEntity(GamePacket packet) noexcept;
};
