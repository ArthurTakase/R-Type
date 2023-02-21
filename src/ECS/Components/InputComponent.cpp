/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** InputComponent
*/

#include <ECS/Components/InputComponent.hpp>

InputComponent::InputComponent() noexcept {}

int InputComponent::getInput() noexcept
{
    if (inputs.empty()) return -1;
    int input = inputs.front();
    inputs.pop();
    return input;
}

void InputComponent::addInput(int input) noexcept
{
    inputs.emplace(input);
}

void InputComponent::clearInputs() noexcept
{
    while (!inputs.empty()) { inputs.pop(); }
}