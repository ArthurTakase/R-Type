/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

/**
 * @brief This class is used to create an error.
 *
 */
class Error : public std::exception
{
  public:
    explicit Error(std::string) noexcept;
    Error(const Error& other) noexcept = default;
    Error(Error&& other) noexcept      = default;
    ~Error() noexcept override         = default;

    Error&      operator=(const Error&) noexcept = default;
    Error&      operator=(Error&&) noexcept      = default;
    const char* what() const noexcept override;

  protected:
  private:
    std::string message_;
};

/**
 * @brief This class is used to create an error when the initialization of an element fails.
 *
 */
class InitError : public Error
{
  public:
    explicit InitError(std::string) noexcept;
    InitError(const InitError& other) noexcept = default;
    InitError(InitError&& other) noexcept      = default;
    ~InitError() noexcept override             = default;

    InitError& operator=(const InitError& rhs) noexcept = default;
    InitError& operator=(InitError&& rhs) noexcept      = default;

  protected:
  private:
};

/**
 * @brief This class is used to create an error when the network execution fails.
 *
 */
class NetworkExecError : public Error
{
  public:
    explicit NetworkExecError(std::string) noexcept;
    NetworkExecError(const NetworkExecError& other) noexcept = default;
    NetworkExecError(NetworkExecError&& other) noexcept      = default;
    ~NetworkExecError() noexcept override                    = default;

    NetworkExecError& operator=(const NetworkExecError& rhs) noexcept = default;
    NetworkExecError& operator=(NetworkExecError&& rhs) noexcept      = default;

  protected:
  private:
};
