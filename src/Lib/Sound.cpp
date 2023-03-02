/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#include <Error/Error.hpp>
#include <Lib/Sound.hpp>

/**
 * It takes a path to a sound file, loads the sound file into a buffer, and then
 * sets the sound object's buffer to the buffer that was just loaded
 *
 * @param path The path to the sound file.
 */
Sound::Sound(const Buffer& buffer)
{
    sound_.setBuffer(buffer.buffer_);
}

/**
 * It plays the sound
 */
void Sound::play() noexcept
{
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