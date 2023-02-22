/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundSystem
*/

#include <ECS/Systems/SoundSystem.hpp>

SoundSystem::SoundSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

void SoundSystem::run()
{
    for (; !it_.isEnd(); ++it_) {
        Entity* entity = it_.get();

        if (!entity->hasComponents<SoundComponent>()) { continue; }

        auto sound = entity->getComponent<SoundComponent>();
        sound->play();
    }
    it_.reset();
}