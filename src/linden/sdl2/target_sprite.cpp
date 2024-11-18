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

}  // namespace linden::sdl2