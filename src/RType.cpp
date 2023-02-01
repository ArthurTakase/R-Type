/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include "RType.hpp"

#include <iostream>
#include <memory>

#include "DrawableComponent.hpp"
#include "HitboxComponent.hpp"
#include "Lib.hpp"
#include "RType.hpp"
#include "TransformComponent.hpp"

RType::RType()
    : _entityManager(std::make_unique<EntityManager>())
    , _hitboxSystem(nullptr)
    , _serializerSystem(nullptr)
{
    // Window
    auto lib = std::make_unique<Lib>();
    lib->getWindow().open(800, 600, "R-Type");
    auto& window = lib->getWindow();

    // EntityManager
    _entityManager->createPlayer();
    // _entityManager->getEntities().back()->addComponent<DrawableComponent>(23, 32, 140, 220, 3);

    // Serializer
    _serializerSystem = std::make_unique<SerializerSystem>(_entityManager);

    auto data = _serializerSystem->Serialize(_entityManager->getEntities().back());
    std::cout << data << std::endl;

    // Loop
    while (window.isOpen()) {
        window.clear();

        auto key = window.getKeyPressed();

        if (key == WINDOW_KEY::QUIT) {
            window.close();
            break;
        }

        _serializerSystem->run();

        window.refresh();
    }

    auto manager = std::make_unique<EntityManager>();
    manager->createPlayer();
    manager->createEnemy();
    manager->createEnemy();
    manager->createPlayer();
    manager->createEnemy();
    manager->createPlayer();

    auto it = EntityIterator<HitboxComponent, TransformComponent>(manager->getEntities());

    std::cout << "Part 1" << std::endl;

    while (!it.isEnd()) {
        std::cout << it.get()->getId() << std::endl;
        ++it;
    }
    it.reset();

    std::cout << "Part 2" << std::endl;

    while (!it.isEnd()) {
        std::cout << it.get()->getId() << std::endl;
        ++it;
    }
    it.reset();
}

RType::~RType() noexcept {}
