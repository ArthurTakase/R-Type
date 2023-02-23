/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Music
*/

#include <Lib/Music.hpp>
#include <iostream>

Music::Music(const std::string& path)
    : music_(std::make_unique<sf::Music>())
{
    if (!music_->openFromFile(path)) std::cerr << "Error: Could not load music from file: " + path << std::endl;

    music_->setLoop(true);
}

void Music::play() noexcept
{
    music_->play();
}

void Music::pause() noexcept
{
    music_->pause();
}

void Music::stop() noexcept
{
    music_->stop();
}

void Music::setVolume(float value) noexcept
{
    music_->setVolume(value);
}

void Music::setLoop(bool value) noexcept
{
    music_->setLoop(value);
}