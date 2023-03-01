/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** InputComponent
*/

#include <ECS/Components/InputComponent.hpp>

InputComponent::InputComponent() noexcept {}

/**
 * If there are no inputs, return -1, otherwise return the first input in the
 * queue.
 *
 * @return The first input in the queue.
 */
int InputComponent::getInput() noexcept
{
    if (inputs.empty()) return -1;
    int input = inputs.front();
    inputs.pop();
    return input;
}

/**
 * It adds an input to the set of inputs
 *
 * @param input The input to add to the component.
 */
void InputComponent::addInput(int input) noexcept
{
    inputs.emplace(input);
}

/**
 * It clears the inputs queue
 */
void InputComponent::clearInputs() noexcept
{
    while (!inputs.empty()) { inputs.pop(); }
}