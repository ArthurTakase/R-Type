/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundComponent
*/

#include <ECS/Components/SoundComponent.hpp>

SoundComponent::SoundComponent(const std::string& path)
    : sound_(path)
{
}

SoundComponent::SoundComponent(const SoundComponent& other) noexcept
    : sound_(other.getSound().getPath())
    , isPlayed_(other.getIsPlayed())
{
}

Sound SoundComponent::getSound() const noexcept
{
    return sound_;
}

bool SoundComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

void SoundComponent::setPlayed(bool value) noexcept
{
    isPlayed_ = value;
}

void SoundComponent::play() noexcept
{
    if (isPlayed_) {
        sound_.play();
        isPlayed_ = false;
    }
}