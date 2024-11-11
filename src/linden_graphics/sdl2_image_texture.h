#pragma once
#include "sdl2_renderer.h"
#include "sdl2_texture.h"

namespace linden::graphics
{
    class SDL2ImageTexture : public SDL2Texture
    {
    public:
        SDL2ImageTexture(const SDL2Renderer& renderer, const std::string& path);
    };
}  // namespace linden::graphics