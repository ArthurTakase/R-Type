/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/BehaviorSystem.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/DrawableSystem.hpp>
#include <ECS/Systems/MouvementSystem.hpp>
#include <ECS/Systems/MusicSystem.hpp>
#include <Lib/Lib.hpp>
#include <NetworkLib/ISocket.hpp>
#include <string_view>

#define SPRITE(id) ("assets/img/r-typesheet" id ".gif")
#define AUDIO(name) ("assets/audio/r-type" name)
#define FONT(name) ("assets/fonts/" name)

/**
 * @brief This class is used to create a menu instance in the client.
 */
class Menu
{
  public:
    Menu();
    ~Menu() noexcept                 = default;
    Menu(const Menu& other) noexcept = delete;
    Menu(Menu&& other) noexcept      = delete;

    Menu& operator=(const Menu& rhs) noexcept = delete;
    Menu& operator=(Menu&& rhs) noexcept      = delete;

    Address run(Window& window);
    bool    getIsOpen() const noexcept;

  private:
    EntityManager     manager_;
    DrawableSystem    drawableSystem_;
    DestroyableSystem destroyableSystem_;
    BehaviorSystem    behaviorSystem_;
    MouvementSystem   mouvementSystem_;
    MusicSystem       musicSystem_;

    std::string ip_     = "";
    std::string port_   = "";
    bool        isOpen_ = true;

    static constexpr unsigned int     MAX_INDEX       = 2;
    static constexpr unsigned int     MAX_VALUE       = 255;
    static constexpr int              MIN_VALUE       = -255;
    static constexpr std::string_view TITLE_PATH      = SPRITE("7");
    static constexpr std::string_view BG_MUSIC_PATH   = AUDIO("loading.wav");
    static constexpr std::string_view FONT_PATH       = FONT("gameboy.ttf");
    static constexpr std::string_view BACKGROUND_PATH = SPRITE("0");
    // methods
    void createMusic(const std::string_view& path) noexcept;
    int  createText(int x, int y, int size, const std::string_view& txt) noexcept;
    int  createIPMenu(Window& window) noexcept;
    int  createTitleMenu(Window& window) noexcept;
    int  createBackground(int x) noexcept;
};