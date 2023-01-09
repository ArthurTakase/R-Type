/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** IsInstanceOf.cpp
*/

#pragma once

namespace Type
{

template <typename Base, typename T>
inline bool instanceOf(const T* ptr)
{
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

}