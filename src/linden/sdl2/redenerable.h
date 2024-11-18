#pragma once

#include "../types.h"

namespace linden::sdl2
{
    struct RenderPosition
    {
        linden::Position position = {0, 0};
        linden::Size size = {0, 0};
    };

    struct RenderRotation
    {
        double angle = 0.0;
        linden::Position center = {0, 0};
        bool flip_horizontal = false;
        bool flip_vertical = false;
    };

    struct RenderConfig
    {
        bool active = true;
        RenderPosition destination;
        RenderPosition source;
        RenderRotation rotation;
    };

    class Renderable
    {
    public:
        // Virtual methods
        virtual void render(RenderConfig configuration) = 0;
        virtual linden::Size get_size() const = 0;

        RenderConfig& update_render_config(RenderConfig& configuration) const;
    };
}  // namespace linden::sdl2