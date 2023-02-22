/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#include <Client/Menu.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <iostream>
#include <vector>

Menu::Menu()
    : drawableSystem_(&manager_)
    , destroyableSystem_(&manager_)
    , behaviorSystem_(&manager_)
    , ip_("")
    , port_("")
    , client_port_("")
{
    createIPMenu();
}

std::vector<std::string> Menu::run() noexcept
{
    auto& window = lib_.getWindow();
    int   input;

    window.open(256, 256, "Menu");
    drawableSystem_.setWindow(&lib_.getWindow());

    while (open) {
        destroyableSystem_.run();
        drawableSystem_.run();
        behaviorSystem_.run();
    }

    window.close();

    return {ip_, port_, client_port_};
}

int Menu::createText(int x, int y, std::string txt) noexcept
{
    auto text = manager_.newEntity();

    text->addComponent(DrawableComponent());
    text->addComponent(TransformComponent(x, y));
    text->addComponent(DestroyableComponent());
    text->addComponent(TextComponent(txt, "assets/fonts/gameboy.ttf", 15, x, y));

    return text->getId();
}

int Menu::createIPMenu() noexcept
{
    createText(60, 10, "RType Tek");
    createText(10, 60, "Server IP:");
    createText(10, 110, "Server Port:");
    createText(10, 160, "Client Port:");

    auto menu = manager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        static auto&                  window = lib_.getWindow();
        int                           input  = window.getKeyPressed();
        static const std::vector<int> numpad = {75, 76, 77, 78, 79, 80, 81, 82, 83, 84};
        // static const std::vector<int>    num    = {27, 28, 29, 51, 31, 56, 33, 34, 35, 26};
        static const std::vector<int>    exit = {255, 36};
        static std::vector<std::string*> txt  = {&ip_, &port_, &client_port_};
        static int                       i    = 0;
        static const std::vector<int>    allX = {80, 130, 180};

        if (std::find(exit.begin(), exit.end(), input) != exit.end()) {
            for (auto& t : txt) *t = "";
            open = false;
        }
        if (std::find(numpad.begin(), numpad.end(), input) != numpad.end()) {
            *txt[i] += std::to_string(input - 75);
            createText(txt[i]->size() * 15, allX[i], std::to_string(input - 75));
        }
        if (input == 48) { // .
            *txt[i] += ".";
            createText(txt[i]->size() * 15, allX[i], ".");
        }
        if (input == 58) { // return
            if (i == 3) open = false;
            else if (txt[i]->length() > 1)
                i++;
            else {
                std::cout << "Invalid input" << std::endl;
            }
        }
        if (input == 59) { // backspace
            if (txt[i]->length() > 0) {
                txt[i]->erase(txt[i]->length() - 1, 1);
                manager_.getEntities().pop_back();
            }
        }
    }});

    menu->addComponent(behavior);

    return menu->getId();
}