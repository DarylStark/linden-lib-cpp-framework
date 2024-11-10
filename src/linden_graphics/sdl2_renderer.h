#pragma once

#include <SDL2/SDL.h>

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
    };
}  // namespace linden::graphics