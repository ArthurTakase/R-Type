/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicSystem
*/

#include <ECS/Systems/MusicSystem.hpp>

MusicSystem::MusicSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

void MusicSystem::run()
{
    for (; !it_.isEnd(); ++it_) {
        Entity* entity = it_.get();

        if (!entity->hasComponent<MusicComponent>()) { continue; }

        entity->getComponent<MusicComponent>()->play();
    }
    it_.reset();
}