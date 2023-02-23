/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#include <Lib/Sound.hpp>
#include <Error/Error.hpp>

Sound::Sound(const std::string& path)
    : path_(path)
{
    if (!buffer_.loadFromFile(path)) throw Error("Error: Could not load sound from file: " + path);

    sound_.setBuffer(buffer_);
}

Sound::~Sound() noexcept
{
    this->stop();
}

void Sound::play() noexcept
{
    sound_.play();
}

void Sound::pause() noexcept
{
    sound_.pause();
}

void Sound::stop() noexcept
{
    sound_.stop();
}

void Sound::setVolume(float value) noexcept
{
    sound_.setVolume(value);
}

std::string Sound::getPath() const noexcept
{
    return path_;
}