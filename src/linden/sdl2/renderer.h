#pragma once

#include <SDL2/SDL.h>

#include "../types.h"

namespace linden::sdl2
{
    class Renderer
    {
    private:
        SDL_Renderer* _renderer_handle;

    public:
        Renderer(SDL_Window* window_handle);
        ~Renderer();

        // Object management
        void cleanup();

        // Retrievers for SDL2 handles
        SDL_Renderer* get_sdl2_renderer_handle() const;
    };
}  // namespace linden::sdl2