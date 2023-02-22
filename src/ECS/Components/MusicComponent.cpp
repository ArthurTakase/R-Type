/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicComponent
*/

#include <ECS/Components/MusicComponent.hpp>

MusicComponent::MusicComponent(const std::string& path)
    : music_(path)
    , path_(path)
{
}

MusicComponent::MusicComponent(const MusicComponent& other) noexcept
    : music_(other.getPath())
    , isPlayed_(other.getIsPlayed())
    , path_(other.getPath())
{
}

bool MusicComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

std::string MusicComponent::getPath() const noexcept
{
    return path_;
}

void MusicComponent::setPlaying(bool value) noexcept
{
    isPlayed_ = value;
}

void MusicComponent::play() noexcept
{
    if (isPlayed_) { music_.play();
    isPlayed_ = false;
}
}
