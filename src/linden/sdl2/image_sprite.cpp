#include "image_sprite.h"

#include <SDL_image.h>

namespace linden::sdl2
{
    ImageSprite::ImageSprite(Renderer& renderer_handle, const std::string& path)
        : Sprite(renderer_handle)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        _texture_handle = SDL_CreateTextureFromSurface(
            _renderer_handle.get_sdl2_renderer_handle(), surface);
        SDL_SetTextureBlendMode(_texture_handle, SDL_BLENDMODE_BLEND);
        SDL_FreeSurface(surface);
    }
}  // namespace linden::sdl2