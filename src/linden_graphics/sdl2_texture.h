#pragma once
#include <SDL2/SDL.h>

#include <memory>
#include <string>

#include "models.h"

// Forward declaration of SDL2Texture
namespace linden::graphics
{
    class SDL2Renderer;
}

// TODO: Mulitple header and CPP files instead of three classes in one?

namespace linden::graphics
{
    enum class TextureAccess
    {
        STATIC = 0,
        STREAMING = 1,
        TARGET = 2
    };

    class SDL2Texture
    {
    protected:
        const SDL2Renderer& _renderer;
        SDL_Texture* _texture;

    public:
        SDL2Texture(const SDL2Renderer& renderer);
        SDL2Texture(const SDL2Renderer& renderer, TextureAccess access,
                    Size size);
        ~SDL2Texture();

        // Get native SDL2 handle
        SDL_Texture* get_sdl2_texture_handle() const;

        // Texture altering
        void set_alpha(uint8_t alpha);

        // Get texture information
        Size get_size() const;
    };
}  // namespace linden::graphics