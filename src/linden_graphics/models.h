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

        Size operator*(const int multiplier) const
        {
            return {
                .width = width * multiplier,
                .height = height * multiplier,
            };
        }
    };

    struct TextureRenderOptions
    {
        bool active = true;
        Position position = {0, 0};
        Size size = {0, 0};
        double angle = 0.0;
        Position rotation_center = {0, 0};
        bool flip_horizontal = false;
        bool flip_vertical = false;
        uint32_t scale = 1;
    };
}  // namespace linden::graphics