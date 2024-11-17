#pragma once

#include <string>

#include "sprite.h"

namespace linden::sdl2
{
    class ImageSprite : public Sprite
    {
    public:
        ImageSprite(Renderer& renderer_handle, const std::string& path);
    };
}  // namespace linden::sdl2