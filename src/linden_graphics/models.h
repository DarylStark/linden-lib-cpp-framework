#pragma once
#include <cstdint>

namespace linden::graphics
{
    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    struct Position
    {
        int x;
        int y;
    };

    struct Size
    {
        int width;
        int height;
    };
}  // namespace linden::graphics