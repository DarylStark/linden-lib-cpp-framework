#pragma once

#include <SDL2/SDL.h>

#include <string>

#include "models.h"

namespace linden::graphics
{
    class SDL2Window
    {
    private:
        SDL_Window* _window_handle;
        SDL_Renderer* _renderer_handle;

    public:
        SDL2Window(const std::string& title, Position position, Size size,
                   uint32_t flags);
        ~SDL2Window();

        // Add parts
        void add_window_renderer();

        // Retrievers
        SDL_Window* get_window_handle() const;
        SDL_Renderer* get_renderer_handle() const;
    };
}  // namespace linden::graphics