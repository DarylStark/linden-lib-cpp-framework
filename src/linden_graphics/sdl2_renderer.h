#pragma once

#include <SDL2/SDL.h>

#include "models.h"

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
    };
}  // namespace linden::graphics