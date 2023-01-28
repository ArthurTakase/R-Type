/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Window.cpp
*/

#include "Window.hpp"

#include <iostream>

/**
 * `Window::Window()` is a constructor function that creates a window with the title "SFML works!" and
 * a size of 800x600
 */
Window::Window()
{
    window.create(sf::VideoMode(800, 600), "SFML works!");
    std::cout << "SFML Window Loaded" << std::endl;
}

/**
 * It closes the window
 */
void Window::close()
{
    window.close();
}

/**
 * It clears the window
 */
void Window::clear()
{
    window.clear();
}

/**
 * It refreshes the window
 */
void Window::refresh()
{
    window.display();
}

/**
 * Returns true if the window is open, false otherwise.
 *
 * @return A boolean value.
 */
bool Window::isOpen()
{
    return window.isOpen();
}

/**
 * If the window is closed, return 255. If a key is pressed, return the key code. Otherwise, return 0
 *
 * @return A bitset of 8 bits.
 */
std::bitset<8> Window::getKeyPressed()
{
    sf::Event event;

    if (!window.pollEvent(event)) return std::bitset<8>(0);
    if (event.type == sf::Event::Closed) return std::bitset<8>(255);
    if (event.type == sf::Event::KeyPressed) return std::bitset<8>(event.key.code);
    return std::bitset<8>(0);
}