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
Sound::Sound(const std::string& path)
    : path_(path)
{
    if (!soundData_.buffer_.loadFromFile(path)) throw Error("Error: Could not load sound from file");

    soundData_.sound_.setBuffer(soundData_.buffer_);
}

/**
 * It plays the sound
 */
void Sound::play() noexcept
{
    soundData_.sound_.play();
}

/**
 * It pauses the sound
 */
void Sound::pause() noexcept
{
    soundData_.sound_.pause();
}

/**
 * It stops the sound
 */
void Sound::stop() noexcept
{
    soundData_.sound_.stop();
}

/**
 * Sets the volume of the sound
 *
 * @param value The volume of the sound, in the range [0, 100].
 */
void Sound::setVolume(float value) noexcept
{
    soundData_.sound_.setVolume(value);
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

/**
 * This function initializes the sound_ and buffer_ members of the SoundData class.
 *
 * @param sound The sound object that will be played.
 * @param buffer The sound buffer to use for the sound.
 */
SoundData::SoundData(sf::Sound sound, sf::SoundBuffer buffer) noexcept
    : sound_(sound)
    , buffer_(buffer)
{
}

/**
 * It copies the sound and buffer from the other SoundData object
 *
 * @param other The SoundData object to copy from.
 */
SoundData::SoundData(const SoundData& other) noexcept
    : sound_(other.sound_)
    , buffer_(other.buffer_)
{
    sound_.setBuffer(buffer_);
}

/**
 * "Move the other object's sound and buffer into this object, and set the sound's
 * buffer to the new buffer."
 *
 * The first line of the function is the function declaration. It's the same as the
 * copy constructor, except that it uses the move constructor syntax
 *
 * @param other The object to move from.
 */
SoundData::SoundData(SoundData&& other) noexcept
    : sound_(std::move(other.sound_))
    , buffer_(std::move(other.buffer_))
{
    sound_.setBuffer(buffer_);
}

/**
 * Copy the data from the right hand side of the assignment operator to the left
 * hand side of the assignment operator.
 *
 * @return A reference to the object that called the function.
 */
SoundData& SoundData::operator=(const SoundData& rhs) noexcept
{
    sound_  = rhs.sound_;
    buffer_ = rhs.buffer_;
    sound_.setBuffer(buffer_);
    return *this;
}

/**
 * "Move the data from the right hand side to the left hand side."
 *
 * The first thing we do is move the sound_ data member from the right hand side
 * to the left hand side
 *
 * @return A reference to the object that called the function.
 */
SoundData& SoundData::operator=(SoundData&& rhs) noexcept
{
    sound_  = std::move(rhs.sound_);
    buffer_ = std::move(rhs.buffer_);
    sound_.setBuffer(buffer_);
    return *this;
}
