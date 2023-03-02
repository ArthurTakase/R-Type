/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Buffer
*/

#include <Error/Error.hpp>
#include <Lib/Buffer.hpp>

Buffer::Buffer(const std::string_view& path)
{
    if (!buffer_.loadFromFile(path.data())) throw Error("Error: Could not load buffer from file" );
}