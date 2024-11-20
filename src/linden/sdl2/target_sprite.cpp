#include "target_sprite.h"

namespace linden::sdl2
{
    TargetSprite::TargetSprite(Renderer& renderer_handle, linden::Size size)
        : Sprite(renderer_handle)
    {
        _texture_handle = SDL_CreateTexture(
            _renderer_handle.get_sdl2_renderer_handle(),
            SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, size.width,
            size.height);
        SDL_SetTextureBlendMode(_texture_handle, SDL_BLENDMODE_BLEND);
    }

    void TargetSprite::fill(const linden::Color& color)
    {
        SDL_SetRenderTarget(_renderer_handle.get_sdl2_renderer_handle(),
                            _texture_handle);
        _renderer_handle.set_draw_color(color);
        _renderer_handle.clear();
        _renderer_handle.reset_target();
    }
}  // namespace linden::sdl2