/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TextComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <Lib/Text.hpp>
#include <functional>
#include <memory>

/**
 * @brief Component assigned to drawable entities.
 */
class TextComponent : public IComponent
{
  public:
    TextComponent();
    TextComponent(const std::string& text, const std::string& fontPath, int fontSize, int x, int y);
    ~TextComponent() noexcept = default;
    TextComponent(const TextComponent& other) noexcept;
    TextComponent(TextComponent&& other) noexcept = delete;

    TextComponent& operator=(const TextComponent& rhs) noexcept = delete;
    TextComponent& operator=(TextComponent&& rhs) noexcept      = delete;

    Text& getText() noexcept;

  private:
    Text text_;
};