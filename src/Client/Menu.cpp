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
#include <ECS/Components/MusicComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/HostHandler.hpp>
#include <iostream>
#include <vector>

Menu::Menu()
    : drawableSystem_(&manager_)
    , destroyableSystem_(&manager_)
    , behaviorSystem_(&manager_)
    , mouvementSystem_(&manager_)
    , musicSystem_(&manager_)
{
}

Address Menu::run(Window& window)
{
    createTitleMenu(window);
    // createMusic(BG_MUSIC_PATH);
    drawableSystem_.setWindow(&window);
    Address serverInfos;

    while (isOpen_) {
        destroyableSystem_.run();
        drawableSystem_.run();
        behaviorSystem_.run();
        mouvementSystem_.run();
        musicSystem_.run();
    }

    serverInfos.port = std::atoi(port_.c_str());
    if (serverInfos.port <= 0) throw Error("Port must be a positive number");
    serverInfos.ip = HostHandler::getIp(ip_.c_str());
    if (serverInfos.ip <= 0) throw Error("No server found with this IP address");

    return serverInfos;
}

bool Menu::getIsOpen() const noexcept
{
    return isOpen_;
}

void Menu::createMusic(const std::string_view& path) noexcept
{
    auto music = manager_.newEntity();

    music->addComponent(MusicComponent(path.data()));
}

int Menu::createText(int posX, int posY, int size, const std::string_view& message) noexcept
{
    auto text = manager_.newEntity();

    text->addComponent(DrawableComponent());
    text->addComponent(TransformComponent(posX, posY));
    text->addComponent(DestroyableComponent());
    auto textComponent = TextComponent(message.data(), FONT_PATH.data(), size, posX, posY);
    text->addComponent(textComponent);

    return text->getId();
}

int Menu::createBackground(int posX, const std::string_view& imagePath) noexcept
{
    auto background = manager_.newEntity();

    background->addComponent(TransformComponent(posX, DEFAULT));
    background->addComponent(MouvementComponent(-1, DEFAULT, 1.0));
    background->addComponent(DestroyableComponent());

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= MIN_VALUE) { transform->setX(MAX_VALUE); }
    }});

    auto  drawable = DrawableComponent(DEFAULT, DEFAULT, MAX_VALUE, MAX_VALUE, DEFAULT);
    auto& sprite   = drawable.getSprite();
    sprite.setSpritePath(BACKGROUND_PATH.data());

    background->addComponent(drawable);
    background->addComponent(behaviorComponent);

    return background->getId();
}

int Menu::createTitleMenu(Window& window) noexcept
{
    int bg1 = createBackground(DEFAULT, BACKGROUND_PATH);
    int bg2 = createBackground(MAX_VALUE, BACKGROUND_PATH);
    int t1  = createText(40, 230, 10, CREDITS_TEXT.data());
    int t2  = createText(75, 200, 10, INSTRUCTIONS.data());

    auto menu = manager_.newEntity();

    menu->addComponent(MouvementComponent(DEFAULT, 1, 1));
    menu->addComponent(TransformComponent(20, 00));
    menu->addComponent(DestroyableComponent());

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&, bg1, bg2, t1, t2](Entity* entity) {
        int                              input = window.getKeyPressed();
        static const std::vector<int>    exit  = {MAX_VALUE, 36};
        static std::vector<std::string*> txt   = {&ip_, &port_};

        if (std::find(exit.begin(), exit.end(), input) != exit.end()) {
            for (auto& t : txt) *t = "";
            isOpen_ = false;
        }
        if (input == RETURN_KEY) {
            createIPMenu(window);
            entity->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t1)->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t2)->getComponent<DestroyableComponent>()->destroy();
        }

        auto mouvement = entity->getComponent<MouvementComponent>();
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getY() >= 30) mouvement->setDirY(DEFAULT);
    }});

    auto  drawable = DrawableComponent(DEFAULT, DEFAULT, 226, 97, 7);
    auto& sprite   = drawable.getSprite();
    sprite.setSpritePath(TITLE_PATH.data());

    menu->addComponent(behavior);
    menu->addComponent(drawable);

    return menu->getId();
}

int Menu::createIPMenu(Window& window) noexcept
{
    createText(55, 10, 15, "Connect to");
    createText(10, 60, 15, "Server IP:");
    createText(10, 120, 15, "Server Port:");
    int t1 = createText(10, 80, 15, "...");
    int t2 = createText(10, 140, 15, "...");

    auto menu = manager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&, t1, t2](Entity* entity) {
        int                              input  = window.getKeyPressed();
        static const std::vector<int>    numpad = {75, 76, 77, 78, 79, 80, 81, 82, 83, 84};
        static const std::vector<int>    num    = {26, 27, 28, 29, 51, 31, 56, 33, 34, 35};
        static const std::vector<int>    exit   = {MAX_VALUE, 36};
        static std::vector<std::string*> txt    = {&ip_, &port_};
        static int                       i      = 0;
        static std::vector<int>          allTxt = {t1, t2};

        if (std::find(exit.begin(), exit.end(), input) != exit.end()) {
            for (auto& t : txt) *t = "";
            isOpen_ = false;
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
        if (input == DOT_KEY) {
            *txt[i] += ".";
            manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
        }
        if (input == RETURN_KEY) {
            if (txt[i]->length() > 1) i++;
            if (i >= MAX_INDEX) isOpen_ = false;
        }
        if (input == BACKSPACE_KEY) {
            if (txt[i]->length() > 0) {
                txt[i]->erase(txt[i]->length() - 1, 1);
                manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
            }
        }
    }});

    menu->addComponent(behavior);

    return menu->getId();
}