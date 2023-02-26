/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundSystem
*/

#include <ECS/Systems/SoundSystem.hpp>

/**
 * It initializes the SoundSystem class
 *
 * @param manager The entity manager that the system will be using.
 */
SoundSystem::SoundSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

/**
 * It iterates through all entities with a SoundComponent and plays the sound
 */
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