/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** IComponent.cpp
*/

#pragma once

#include <cstddef>
#include <string>

/**
 * @brief Interface for all components
 */
class IComponent
{
  public:
    IComponent() noexcept          = default;
    virtual ~IComponent() noexcept = default;
    // IComponent(const IComponent& other) noexcept = delete;
    // IComponent(IComponent&& other) noexcept      = delete;
    // IComponent& operator=(const IComponent& rhs) noexcept = delete;
    // IComponent& operator=(IComponent&& rhs) noexcept      = delete;
};