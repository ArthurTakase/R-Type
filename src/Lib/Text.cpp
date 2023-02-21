/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Text.cpp
*/

#include <Lib/Text.hpp>
#include <iostream>

Text::Text()
    : textString_("")
    , fontPath_("")
    , fontSize_(0)
    , x_(0)
    , y_(0)
    , color_(sf::Color::White)
    , text_("", font_)
{
}

Text::Text(const std::string& text, const std::string& fontPath, int fontSize, int x, int y)
    : textString_(text)
    , fontPath_(fontPath)
    , fontSize_(fontSize)
    , x_(x)
    , y_(y)
    , color_(sf::Color::White)
    , text_(text.c_str(), font_)
{
    if (text == "" || fontPath == "") { return; }

    if (!font_.loadFromFile(fontPath)) {
        std::cerr << "Error: Could not load font from file: " << fontPath << std::endl;
    }
    text_.setFont(font_);
    text_.setString(textString_);
    text_.setCharacterSize(fontSize);
    text_.setPosition(x, y);
}

void Text::setTextString(const std::string& text)
{
    textString_ = text;
    text_.setString(textString_);
}

void Text::setFontPath(const std::string& path)
{
    fontPath_ = path;

    if (!font_.loadFromFile(fontPath_)) {
        std::cerr << "Error: Could not load font from file: " << fontPath_ << std::endl;
    }
    text_.setFont(font_);
}

void Text::setFontSize(int size)
{
    fontSize_ = size;
    text_.setCharacterSize(fontSize_);
}

void Text::setX(int x)
{
    this->x_ = x;
    text_.setPosition(x, y_);
}

void Text::setY(int y)
{
    this->y_ = y;
    text_.setPosition(x_, y);
}

void Text::setColor(int r, int g, int b, int a)
{
    color_ = sf::Color(r, g, b, a);
    text_.setFillColor(color_);
}

void* Text::getText()
{
    return static_cast<void*>(&text_);
}

void* Text::getFont()
{
    return static_cast<void*>(&font_);
}

void* Text::getColor()
{
    return static_cast<void*>(&color_);
}

int Text::getX() const
{
    return x_;
}

int Text::getY() const
{
    return y_;
}

int Text::getFontSize() const
{
    return fontSize_;
}

std::string Text::getTextString() const
{
    return textString_;
}

std::string Text::getFontPath() const
{
    return fontPath_;
}