#pragma once

#include <cmath>

namespace Tools
{
int curve(float amplitude, float period, int x) noexcept
{
    return amplitude * sin(period * x);
}
}
