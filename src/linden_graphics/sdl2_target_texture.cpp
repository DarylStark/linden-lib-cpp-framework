#include "sdl2_target_texture.h"

#include <iostream>

namespace linden::graphics
{
    SDL2TargetTexture::SDL2TargetTexture(const SDL2Renderer& renderer,
                                         Size size)
        : SDL2Texture(renderer, TextureAccess::TARGET, size)
    {
    }

    SDL2TargetTexture::SDL2TargetTexture(const SDL2Renderer& renderer,
                                         SDL2Texture& src_texture,
                                         Position src_position, Size src_size)
        : SDL2Texture(renderer, TextureAccess::TARGET, src_size)
    {
        add_texture(src_texture, src_position, src_size, {0, 0}, src_size);
    }

    void SDL2TargetTexture::add_texture(SDL2Texture& src_texture,
                                        Position src_position, Size src_size,
                                        Position dst_position, Size dst_size)
    {
        SDL_Rect src = {src_position.x, src_position.y, src_size.width,
                        src_size.height};
        SDL_Rect dst = {dst_position.x, dst_position.y, dst_size.width,
                        dst_size.height};

        SDL_SetRenderTarget(_renderer.get_sdl2_renderer_handle(), _texture);
        int32_t x =
            SDL_RenderCopy(_renderer.get_sdl2_renderer_handle(),
                           src_texture.get_sdl2_texture_handle(), &src, &dst);
        SDL_SetRenderTarget(_renderer.get_sdl2_renderer_handle(), nullptr);
    }
}  // namespace linden::graphics