/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#include <Lib/Sound.hpp>
#include <Error/Error.hpp>

#include <iostream>

/**
 * It takes a path to a sound file, loads the sound file into a buffer, and then
 * sets the sound object's buffer to the buffer that was just loaded
 *
 * @param path The path to the sound file.
 */
Sound::Sound(const std::string& path)
    : path_(path)
{
    if (!buffer_.loadFromFile(path)) throw Error("Error: Could not load sound from file");

    sound_.setBuffer(buffer_);
}

/**
 * It stops the sound, if it's playing, and then it destroys the sound
 */
Sound::~Sound() noexcept
{
    this->stop();
}

/**
 * It plays the sound
 */
void Sound::play() noexcept
{
    std::cout << "Playing sound" << std::endl;
    sound_.play();
}

/**
 * It pauses the sound
 */
void Sound::pause() noexcept
{
    sound_.pause();
}

/**
 * It stops the sound
 */
void Sound::stop() noexcept
{
    sound_.stop();
}

/**
 * Sets the volume of the sound
 *
 * @param value The volume of the sound, in the range [0, 100].
 */
void Sound::setVolume(float value) noexcept
{
    sound_.setVolume(value);
}

/**
 * This function returns the path of the sound.
 *
 * @return The path of the sound file.
 */
std::string Sound::getPath() const noexcept
{
    return path_;
}