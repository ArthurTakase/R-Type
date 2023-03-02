/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Tools
*/

#pragma once
#include <string_view>

#define SPRITE(id) ("assets/img/r-typesheet" id ".gif")
#define AUDIO(name) ("assets/audio/" name)
#define FONT(name) ("assets/fonts/" name)

static constexpr std::string_view PIOU_PATH     = AUDIO("piou.wav");
static constexpr std::string_view SHOOT_PATH    = AUDIO("shoot.wav");
static constexpr std::string_view BG_MUSIC_PATH = AUDIO("loading.wav");
