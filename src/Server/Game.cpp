/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Server/Game.hpp>
#include <iostream>

RType::RType()
    : hitboxSystem_(&entityManager_)
    , behaviorSystem_(&entityManager_)
    , mouvementSystem_(&entityManager_)
    , animationSystem_(&entityManager_)
{
}

void RType::stop() noexcept
{
    looping_ = false;
}

void RType::reset() noexcept
{
    looping_ = true;
}

void RType::run() noexcept
{
    hitboxSystem_.run();
    behaviorSystem_.run();
    mouvementSystem_.run();
    animationSystem_.run();
}

RType::~RType() noexcept {}

HitboxSystem& RType::getHitboxSystem() noexcept
{
    return hitboxSystem_;
}

BehaviorSystem& RType::getBehaviorSystem() noexcept
{
    return behaviorSystem_;
}

EntityManager& RType::getManager() noexcept
{
    return entityManager_;
}

int RType::createPlayer(int x, int y) noexcept
{
    auto player = entityManager_.newEntity();

    auto hitbox = HitboxComponent(15, 21);
    hitbox.setOnCollision(
        std::function<void(Entity * entity)>{[](Entity* entity) { std::cout << "Collision" << std::endl; }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto input = entity->getComponent<InputComponent>();
        auto mouv  = entity->getComponent<MouvementComponent>();
        auto trans = entity->getComponent<TransformComponent>();
        int  lastInput;

        while ((lastInput = input->getInput()) != -1) {
            std::cout << "Entity " << entity->getId() << " Input " << lastInput << std::endl;
            switch (lastInput) {
                case Input::LeftArrow: mouv->setDir(-1, 0); break;
                case Input::RightArrow: mouv->setDir(1, 0); break;
                case Input::UpArrow: mouv->setDir(0, -1); break;
                case Input::DownArrow: mouv->setDir(0, 1); break;
                case Input::Space: createPlayerBullet(trans->getX(), trans->getY()); break;
                case Input::Shift: mouv->setDir(0, 0); break;
            }
        }
    }});

    player->addComponent(hitbox);
    player->addComponent(behavior);
    player->addComponent(DrawableComponent(0, 0, 36, 40, 5));
    player->addComponent(AnimationComponent(533, 0.1));
    player->addComponent(TransformComponent(x, y));
    player->addComponent(StatComponent(100, 5));
    player->addComponent(MouvementComponent(0, 0, 5.0));
    player->addComponent(InputComponent());

    return player->getId();
}

int RType::createPlayerBullet(int x, int y) noexcept
{
    auto bullet = entityManager_.newEntity();

    bullet->addComponent(TransformComponent(x, y));
    bullet->addComponent(MouvementComponent(1, 0, 2.0));
    bullet->addComponent(DrawableComponent(0, 0, 36, 40, 5));

    return 0;
}

int RType::createEnemy(int x, int y) noexcept
{
    auto enemy = entityManager_.newEntity();

    enemy->addComponent(DrawableComponent(0, 0, 18, 18, 3));
    enemy->addComponent(AnimationComponent(205, 0.1));
    enemy->addComponent(TransformComponent(x, y));

    return enemy->getId();
}

int RType::createBackground(int x) noexcept
{
    auto background = entityManager_.newEntity();

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= -255) { transform->setX(255); }
    }});

    background->addComponent(TransformComponent(x, 0));
    background->addComponent(DrawableComponent(0, 0, 255, 255, BACKGROUND_ID));
    background->addComponent(behaviorComponent);
    background->addComponent(MouvementComponent(-1, 0, 1.0));

    return background->getId();
}

void RType::init() noexcept
{
    createBackground(0);
    createBackground(255);
    createEnemy(200, 120);
}