#pragma once

#include "models.h"
#include "sdl2_renderer.h"
#include "sdl2_texture.h"

namespace linden::graphics
{
    class SDL2TargetTexture : public SDL2Texture
    {
    public:
        SDL2TargetTexture(const SDL2Renderer& renderer, Size size);
        SDL2TargetTexture(const SDL2Renderer& renderer,
                          SDL2Texture& src_texture, Position src_position,
                          Size src_size);
        void add_texture(SDL2Texture& src_texture, Position src_position,
                         Size src_size, Position dst_position, Size dst_size);
    };
}  // namespace linden::graphics