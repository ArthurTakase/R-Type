/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundSystem
*/

#pragma once

#include <ECS/Components/SoundComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/SoundManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief A system that will handle and update all SoundComponents contained inside our entities.
 */
class SoundSystem
{
  public:
    SoundSystem(EntityManager* manager, std::vector<std::string_view> listPaths) noexcept;
    SoundSystem(const SoundSystem& other) noexcept = delete;
    SoundSystem(SoundSystem&& other) noexcept      = delete;
    ~SoundSystem() noexcept                        = default;

    SoundSystem& operator=(const SoundSystem& rhs) noexcept = delete;
    SoundSystem& operator=(SoundSystem&& rhs) noexcept      = delete;

    void    run();
    Buffer& getBufferFromPath(const std::string_view& path);

  protected:
  private:
    EntityIterator<SoundComponent> it_;
    EntityManager*                 entityManager_;
    SoundManager                   soundManager_;
};