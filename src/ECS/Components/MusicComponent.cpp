/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicComponent
*/

#include <ECS/Components/MusicComponent.hpp>

MusicComponent::MusicComponent(const std::string_view& path)
    : music_(path.data())
{
}

bool MusicComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

void MusicComponent::setPlaying(bool value) noexcept
{
    isPlayed_ = value;
}

void MusicComponent::play() noexcept
{
    if (isPlayed_) {
        music_.play();
        isPlayed_ = false;
    }
}
