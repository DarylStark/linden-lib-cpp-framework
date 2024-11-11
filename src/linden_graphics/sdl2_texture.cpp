#include "sdl2_texture.h"

#include "sdl2_renderer.h"

namespace linden::graphics
{
    SDL2Texture::SDL2Texture(const SDL2Renderer& renderer)
        : _texture(nullptr), _renderer(renderer)
    {
    }

    SDL2Texture::SDL2Texture(const SDL2Renderer& renderer, TextureAccess access,
                             Size size)
        : _renderer(renderer)
    {
        _texture = SDL_CreateTexture(
            renderer.get_sdl2_renderer_handle(), SDL_PIXELFORMAT_ARGB8888,
            static_cast<int>(access), size.width, size.height);
        SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
        // TODO: Exception
    }

    SDL2Texture::~SDL2Texture()
    {
        if (_texture != nullptr) SDL_DestroyTexture(_texture);
    }

    SDL_Texture* SDL2Texture::get_sdl2_texture_handle() const
    {
        return _texture;
    }

    void SDL2Texture::set_alpha(uint8_t alpha)
    {
        SDL_SetTextureAlphaMod(_texture, alpha);
    }

    Size SDL2Texture::get_size() const
    {
        int width, height;
        SDL_QueryTexture(_texture, nullptr, nullptr, &width, &height);
        return {width, height};
    }
}  // namespace linden::graphics