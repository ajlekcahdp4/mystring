#pragma once

#include <math.h>

namespace power_two
{
size_t nearest_from_above_power_of_two (size_t N)
{
    size_t nearest = 0;

    for ( size_t i = 1; nearest <= N; i++ )
        nearest = 1 << i;

    return nearest;
}
}   // namespace power_two