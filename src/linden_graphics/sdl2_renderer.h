#pragma once

#include <SDL2/SDL.h>

#include "models.h"

// Forward declaration of SDL2Texture
namespace linden::graphics
{
    class SDL2Texture;
}

namespace linden::graphics
{
    class SDL2Renderer
    {
    private:
        SDL_Renderer* _renderer_handle;

    public:
        SDL2Renderer(SDL_Window* window_handle);
        ~SDL2Renderer();

        // Get native SDL2 handle
        SDL_Renderer* get_sdl2_renderer_handle() const;

        // Renderer altering
        void clear();
        void clear(Color color);
        void render();

        // Textures
        void render_texture(const SDL2Texture& texture);
        void render_texture(const SDL2Texture& texture,
                            TextureRenderOptions options);
    };
}  // namespace linden::graphics