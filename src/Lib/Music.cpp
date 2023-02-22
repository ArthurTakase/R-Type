/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Music
*/

#include <Error/Error.hpp>
#include <Lib/Music.hpp>

Music::Music(const std::string& path)
{
    if (!music_.openFromFile(path)) throw Error("Error: Could not load music from file: " + path);

    music_.setLoop(true);
}

Music::~Music() noexcept
{
    this->stop();
}

void Music::play() noexcept
{
    music_.play();
}

void Music::pause() noexcept
{
    music_.pause();
}

void Music::stop() noexcept
{
    music_.stop();
}

void Music::setVolume(float value) noexcept
{
    music_.setVolume(value);
}

void Music::setLoop(bool value) noexcept
{
    music_.setLoop(value);
}