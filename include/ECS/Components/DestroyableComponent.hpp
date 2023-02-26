/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DestroyableComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <Lib/Sprite.hpp>
#include <Lib/Timer.hpp>
#include <functional>
#include <memory>

/**
 * @brief Component assigned to drawable entities.
 */
class DestroyableComponent : public IComponent
{
  public:
    DestroyableComponent() noexcept;
    DestroyableComponent(int destroy) noexcept;
    ~DestroyableComponent() noexcept                                 = default;
    DestroyableComponent(const DestroyableComponent& other) noexcept = default;
    DestroyableComponent(DestroyableComponent&& other) noexcept      = default;

    DestroyableComponent& operator=(const DestroyableComponent& rhs) noexcept = default;
    DestroyableComponent& operator=(DestroyableComponent&& rhs) noexcept      = default;

    bool getDestroyed() const noexcept;
    void destroy() noexcept;

  private:
    bool destroyed_ = false;
};