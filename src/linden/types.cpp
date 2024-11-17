#include "types.h"

namespace linden
{
    Size Size::operator*(const int multiplier) const
    {
        return {
            .width = width * multiplier,
            .height = height * multiplier,
        };
    }

    Size Size::operator/(const int divider) const
    {
        return {
            .width = width / divider,
            .height = height / divider,
        };
    }

    Size& operator*=(const int multiplier, Size& size)
    {
        size.width *= multiplier;
        size.height *= multiplier;
        return size;
    }

    Size& operator/=(const int divider, Size& size)
    {
        size.width /= divider;
        size.height /= divider;
        return size;
    }
}  // namespace linden