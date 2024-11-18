#pragma once

#include <SDL2/SDL.h>

#include "../types.h"

namespace linden::sdl2
{
    class Renderer
    {
    private:
        SDL_Renderer* _renderer_handle = nullptr;

    public:
        Renderer() = default;

        Renderer(SDL_Window* window_handle);
        ~Renderer();

        // Object management
        void cleanup();

        // Initializer
        void initialize(SDL_Window* window_handle);

        // Retrievers for SDL2 handles
        SDL_Renderer* get_sdl2_renderer_handle() const;

        // Render methods
        void present();
        void set_draw_color(const linden::Color& color);
        void clear();

        // Target control
        void reset_target();
    };
}  // namespace linden::sdl2