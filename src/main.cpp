/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** main
*/

#include <SFML/Window.hpp>
#include <bitset>
#include <iostream>
#include <memory>

#include "Entity.hpp"
#include "HitboxComponent.hpp"
#include "RType.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "TransformComponent.hpp"

int main()
{
    // Create a window for input
    sf::RenderWindow window(sf::VideoMode(600, 600), "Input Example");

    // Create a variable to hold the input value
    int input = 0;
    // Create a variable to hold the key pressed
    sf::Keyboard::Key pressedKey = sf::Keyboard::Unknown;

    // Run the program as long as the window is open
    while (window.isOpen()) {
        // Check for events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Handle the "Close" event
            if (event.type == sf::Event::Closed) { window.close(); }
            // Handle key pressed events
            if (event.type == sf::Event::KeyPressed) {
                // check if a number key is pressed
                if (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9) {
                    // assign the number to the input variable
                    input      = event.key.code - sf::Keyboard::Num0;
                    pressedKey = event.key.code;
                }
                input = event.key.code;
            }
        }

        // Clear the window
        window.clear();

        // Draw the input value on the screen
        sf::Font font;
        sf::Text text;
        if (!font.loadFromFile("fonts/Hack Regular Nerd Font Complete Mono Windows Compatible.ttf")) break;
        text.setString("Pressed key: " + std::to_string(pressedKey) + "\nInput value: " + std::to_string(input));
        text.setFont(font);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        text.setCharacterSize(24);
        window.draw(text);

        // Display the window
        window.display();
        std::bitset<8> binary(input);
        std::cout << binary << std::endl;
    }
    return 0;
}
