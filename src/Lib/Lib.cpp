/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Lib.cpp
*/

#include "Lib.hpp"

#include <iostream>

/**
 * The constructor of the Lib class is called when the library is loaded
 */
Lib::Lib()
{
    std::cout << "SFML Loaded" << std::endl;
}

/**
 * This function returns a reference to the window object.
 *
 * @return A reference to the window object.
 */
Window& Lib::getWindow()
{
    return window;
}