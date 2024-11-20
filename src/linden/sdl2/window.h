#pragma once

#include <SDL2/SDL.h>

#include <memory>
#include <string>

#include "../types.h"
#include "renderer.h"

namespace linden::sdl2
{
    class Window
    {
    private:
        SDL_Window* _window_handle;
        Renderer _renderer;

    public:
        Window(const std::string& title, linden::Position position,
               linden::Size size, uint32_t flags = 0);
        ~Window();

        // Object management
        void cleanup();

        // Retrieve window information
        Size get_size() const;
        Size get_drawable_size() const;
        Position get_window_position() const;

        // Retrieve "our" objects
        Renderer& get_renderer();

        // Retrievers for SDL2 handles
        SDL_Window* get_sdl2_window_handle() const;

        // Methods for the renderer. Will be delegated to the renderer object
        void present();
        void set_draw_color(const linden::Color& color);
        void clear();
    };
}  // namespace linden::sdl2