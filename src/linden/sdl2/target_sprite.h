#pragma once

#include "../types.h"
#include "sprite.h"

namespace linden::sdl2
{
    class TargetSprite : public Sprite
    {
    public:
        TargetSprite(Renderer& renderer_handle, linden::Size size);
        virtual void fill(const linden::Color& color);
    };
}  // namespace linden::sdl2