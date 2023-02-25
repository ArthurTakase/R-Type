#include <Tools/Curve.hpp>
#include <cmath>

int Tools::curve(float amplitude, float period, int x) noexcept
{
    return amplitude * sin(period * x);
}