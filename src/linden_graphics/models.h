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

    struct TextureRenderOptions
    {
        Position position;
        Size size;
        double angle;
        Position rotation_center;
        bool flip_horizontal;
        bool flip_vertical;
    };
}  // namespace linden::graphics