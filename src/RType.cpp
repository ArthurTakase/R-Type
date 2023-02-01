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
    std::unique_ptr<Entity> entity    = std::make_unique<Entity>(_entityManager->createId());
    auto                    transform = TransformComponent(234, 69);
    auto                    drawable  = DrawableComponent(23, 32, 140, 220, 3);
    entity->addComponent(transform);
    entity->addComponent(drawable);
    _serializerSystem = std::make_unique<SerializerSystem>(_entityManager);

    auto data = _serializerSystem->Serialize(entity);
    std::cout << data << std::endl;
    _serializerSystem->DeSerialize(data);

    // Loop
    // while (window.isOpen()) {
    //     window.clear();

    //     auto key = window.getKeyPressed();

    //     if (key == WINDOW_KEY::QUIT) {
    //         window.close();
    //         break;
    //     }

    //     _serializerSystem->run();

    //     window.refresh();
    // }
}

RType::~RType() noexcept {}
