/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextComponent
*/

#include <ECS/Components/TextComponent.hpp>

TextComponent::TextComponent() {}

TextComponent::TextComponent(const std::string& text, const std::string& fontPath, int fontSize, int x, int y)
    : text_(text, fontPath, fontSize, x, y)
{
}

TextComponent::TextComponent(const TextComponent& other) noexcept
    : text_(other.text_)
{
}

Text& TextComponent::getText() noexcept
{
    return text_;
}