/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DestroyableComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>

/**
 * @brief Component assigned to drawable entities.
 */
class DestroyableComponent : public IComponent
{
  public:
    DestroyableComponent() noexcept = default;
    DestroyableComponent(int destroy) noexcept;
    DestroyableComponent(const DestroyableComponent& other) noexcept = default;
    DestroyableComponent(DestroyableComponent&& other) noexcept      = default;
    ~DestroyableComponent() noexcept                                 = default;

    DestroyableComponent& operator=(const DestroyableComponent& rhs) noexcept = default;
    DestroyableComponent& operator=(DestroyableComponent&& rhs) noexcept      = default;

    bool getDestroyed() const noexcept;
    void destroy() noexcept;

  private:
    bool destroyed_ = false;
};