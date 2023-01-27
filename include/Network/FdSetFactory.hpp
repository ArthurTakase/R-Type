/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** FdSetFactory
*/

#pragma once

#include <memory>

#include "FdSet.hpp"

class FdSetFactory
{
  public:
    FdSetFactory() noexcept                          = delete;
    FdSetFactory(const FdSetFactory& other) noexcept = delete;
    FdSetFactory(FdSetFactory&& other) noexcept      = delete;
    ~FdSetFactory() noexcept                         = delete;

    FdSetFactory& operator=(const FdSetFactory& rhs) noexcept = delete;
    FdSetFactory& operator=(FdSetFactory&& rhs) noexcept      = delete;

    static std::unique_ptr<FdSet> createFdSet();

  protected:
  private:
};