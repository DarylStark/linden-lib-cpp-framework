#pragma once

#include <SDL2/SDL.h>

#include <memory>
#include <string>

#include "models.h"
#include "sdl2_renderer.h"

namespace linden::graphics
{
    class SDL2Window
    {
    private:
        SDL_Window* _window_handle;
        std::shared_ptr<SDL2Renderer> _renderer;

    public:
        SDL2Window(const std::string& title, Position position, Size size,
                   uint32_t flags);
        ~SDL2Window();

        // Add parts
        void add_window_renderer();

        // Retrieve window information
        Size get_window_size() const;
        Size get_drawable_size() const;

        // Retrieve "our" objects
        std::shared_ptr<SDL2Renderer> get_renderer() const;

        // Retrievers for SDL2 handles
        SDL_Window* get_sdl2_window_handle() const;
    };
}  // namespace linden::graphics