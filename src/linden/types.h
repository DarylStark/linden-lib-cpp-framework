#pragma once

#include <cstdint>

namespace linden
{
    class Color
    {
    public:
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
    };

    class Position
    {
    public:
        int x;
        int y;
    };

    class Size
    {
    public:
        uint32_t width;
        uint32_t height;

        // Operators
        Size operator*(const int multiplier) const;
        Size operator/(const int divider) const;
        Size& operator*=(const int multiplier) const;
        Size& operator/=(const int divider) const;
    };
}  // namespace linden