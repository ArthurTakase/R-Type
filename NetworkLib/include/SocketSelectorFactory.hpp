/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SocketSelectorFactory
*/

#pragma once
#include <memory>

#include "SocketSelector.hpp"

class SocketSelectorFactory
{
  public:
    SocketSelectorFactory() noexcept                                   = delete;
    SocketSelectorFactory(const SocketSelectorFactory& other) noexcept = delete;
    SocketSelectorFactory(SocketSelectorFactory&& other) noexcept      = delete;
    ~SocketSelectorFactory() noexcept                                  = delete;

    SocketSelectorFactory& operator=(const SocketSelectorFactory& rhs) noexcept = delete;
    SocketSelectorFactory& operator=(SocketSelectorFactory&& rhs) noexcept      = delete;

    static std::unique_ptr<SocketSelector> createSocketSelector();

  protected:
  private:
};