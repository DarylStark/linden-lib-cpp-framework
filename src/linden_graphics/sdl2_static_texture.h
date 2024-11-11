#pragma once

#include "sdl2_texture.h"

namespace linden::graphics
{
    class SDL2StaticTexture : public SDL2Texture
    {
    public:
        SDL2StaticTexture(const SDL2Renderer& renderer, Size size);
    };
}  // namespace linden::graphics