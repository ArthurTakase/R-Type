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
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Components/MusicComponent.hpp>
#include <iostream>
#include <vector>

Menu::Menu()
    : drawableSystem_(&manager_)
    , destroyableSystem_(&manager_)
    , behaviorSystem_(&manager_)
    , mouvementSystem_(&manager_)
    , musicSystem_(&manager_)
{
    createTitleMenu();
    createMusic();
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
        mouvementSystem_.run();
        musicSystem_.run();
    }

    window.close();

    return {ip_, port_, client_port_};
}

void Menu::createMusic() noexcept
{
    auto music = manager_.newEntity();

    music->addComponent(MusicComponent("assets/audio/loading.wav"));
}

int Menu::createText(int x, int y, int size, std::string txt) noexcept
{
    auto text = manager_.newEntity();

    text->addComponent(DrawableComponent());
    text->addComponent(TransformComponent(x, y));
    text->addComponent(DestroyableComponent());
    auto textComponent = TextComponent(txt, "assets/fonts/gameboy.ttf", size, x, y);
    text->addComponent(textComponent);

    return text->getId();
}

int Menu::createBackground(int x) noexcept
{
    auto background = manager_.newEntity();

    background->addComponent(TransformComponent(x, 0));
    background->addComponent(MouvementComponent(-1, 0, 1.0));
    background->addComponent(DestroyableComponent());

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= -255) { transform->setX(255); }
    }});

    auto  drawable = DrawableComponent(0, 0, 255, 255, 0);
    auto& sprite   = drawable.getSprite();
    sprite.setSpritePath("assets/img/r-typesheet0.gif");

    background->addComponent(drawable);
    background->addComponent(behaviorComponent);

    return background->getId();
}

int Menu::createTitleMenu() noexcept
{
    int bg1 = createBackground(0);
    int bg2 = createBackground(255);
    int t1  = createText(40, 230, 10, "@lefeudecamps 2023");
    int t2  = createText(75, 200, 10, "Press Enter");

    auto menu = manager_.newEntity();

    menu->addComponent(MouvementComponent(0, 1, 1));
    menu->addComponent(TransformComponent(20, 00));
    menu->addComponent(DestroyableComponent());

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&, bg1, bg2, t1, t2](Entity* entity) {
        static auto&                     window = lib_.getWindow();
        int                              input  = window.getKeyPressed();
        static const std::vector<int>    exit   = {255, 36};
        static std::vector<std::string*> txt    = {&ip_, &port_, &client_port_};

        if (std::find(exit.begin(), exit.end(), input) != exit.end()) {
            for (auto& t : txt) *t = "";
            open = false;
        }
        if (input == 58) // return
        {
            createIPMenu();
            entity->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t1)->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t2)->getComponent<DestroyableComponent>()->destroy();
        }

        auto mouvement = entity->getComponent<MouvementComponent>();
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getY() >= 30) mouvement->setDirY(0);
    }});

    auto  drawable = DrawableComponent(0, 0, 226, 97, 7);
    auto& sprite   = drawable.getSprite();
    sprite.setSpritePath("assets/img/r-typesheet7.gif");

    menu->addComponent(behavior);
    menu->addComponent(drawable);

    return menu->getId();
}

int Menu::createIPMenu() noexcept
{
    createText(55, 10, 15, "Connect to");
    createText(10, 60, 15, "Server IP:");
    createText(10, 120, 15, "Server Port:");
    createText(10, 180, 15, "Client Port:");
    int t1 = createText(10, 80, 15, "...");
    int t2 = createText(10, 140, 15, "...");
    int t3 = createText(10, 200, 15, "...");

    auto menu = manager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&, t1, t2, t3](Entity* entity) {
        static auto&                     window = lib_.getWindow();
        int                              input  = window.getKeyPressed();
        static const std::vector<int>    numpad = {75, 76, 77, 78, 79, 80, 81, 82, 83, 84};
        static const std::vector<int>    num    = {26, 27, 28, 29, 51, 31, 56, 33, 34, 35};
        static const std::vector<int>    exit   = {255, 36};
        static std::vector<std::string*> txt    = {&ip_, &port_, &client_port_};
        static int                       i      = 0;
        static std::vector<int>          allTxt = {t1, t2, t3};

        if (std::find(exit.begin(), exit.end(), input) != exit.end()) {
            for (auto& t : txt) *t = "";
            open = false;
        }
        if (std::find(numpad.begin(), numpad.end(), input) != numpad.end()) {
            *txt[i] += std::to_string(input - 75);
            manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
        }
        if (std::find(num.begin(), num.end(), input) != num.end()) {
            if (input == 51) *txt[i] += "4";
            else if (input == 56)
                *txt[i] += "6";
            else
                *txt[i] += std::to_string(input - 26);
            manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
        }
        if (input == 48) { // .
            *txt[i] += ".";
            manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
        }
        if (input == 58) { // return
            if (txt[i]->length() > 1) i++;
            if (i >= 3) open = false;
        }
        if (input == 59) { // backspace
            if (txt[i]->length() > 0) {
                txt[i]->erase(txt[i]->length() - 1, 1);
                manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
            }
        }
    }});

    menu->addComponent(behavior);

    return menu->getId();
}