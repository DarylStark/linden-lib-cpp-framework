#include "sdl2_image_texture.h"

#include <SDL_image.h>

namespace linden::graphics
{
    SDL2ImageTexture::SDL2ImageTexture(const SDL2Renderer& renderer,
                                       const std::string& path)
        : SDL2Texture(renderer)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        _texture = SDL_CreateTextureFromSurface(
            renderer.get_sdl2_renderer_handle(), surface);
        SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
        SDL_FreeSurface(surface);
        // TODO: Exception
    }
}  // namespace linden::graphics