/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Text.cpp
*/

#pragma once

#include <SFML/Graphics.hpp>

class Text
{
  public:
    Text();
    Text(const std::string& text, const std::string& fontPath, int fontSize, int x, int y);
    ~Text() noexcept                 = default;
    Text(const Text& other) noexcept = delete;
    Text(Text&& other) noexcept      = delete;

    Text& operator=(const Text& rhs) noexcept = delete;
    Text& operator=(Text&& rhs) noexcept      = delete;

    void        setTextString(const std::string& text);
    void        setFontPath(const std::string& path);
    void        setFontSize(int size);
    void        setX(int x);
    void        setY(int y);
    void        setColor(int r, int g, int b, int a);
    void*       getText();
    void*       getFont();
    void*       getColor();
    int         getX() const;
    int         getY() const;
    int         getFontSize() const;
    std::string getTextString() const;
    std::string getFontPath() const;

  private:
    sf::Text    text_;
    sf::Font    font_;
    std::string textString_;
    std::string fontPath_;
    int         fontSize_;
    int         x_;
    int         y_;
    sf::Color   color_;
};