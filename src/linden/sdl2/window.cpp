#include "window.h"

#include "exceptions.h"

namespace linden::sdl2
{
    Window::Window(const std::string& title, Position position, Size size,
                   uint32_t sdl2_flags)
    {
        _window_handle = SDL_CreateWindow(title.c_str(), position.x, position.y,
                                          size.width, size.height, sdl2_flags);
        if (!_window_handle)
            throw SDL2WindowCreationException("Failed to create SDL2 window: " +
                                              std::string(SDL_GetError()));

        // Create the renderer
        _renderer.initialize(_window_handle);

        return;
    }

    Window::~Window()
    {
        cleanup();
    }

    void Window::cleanup()
    {
        _renderer.cleanup();
        if (_window_handle) SDL_DestroyWindow(_window_handle);
    }

    Size Window::get_size() const
    {
        int width, height;
        SDL_GetWindowSize(_window_handle, &width, &height);
        return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
    }

    Size Window::get_drawable_size() const
    {
        int width, height;
        SDL_GL_GetDrawableSize(_window_handle, &width, &height);
        return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
    }

    Position Window::get_window_position() const
    {
        int x, y;
        SDL_GetWindowPosition(_window_handle, &x, &y);
        return {x, y};
    }

    Renderer& Window::get_renderer()
    {
        return _renderer;
    }

    SDL_Window* Window::get_sdl2_window_handle() const
    {
        return _window_handle;
    }

    void Window::present()
    {
        _renderer.present();
    }
    void Window::set_draw_color(const linden::Color& color)
    {
        _renderer.set_draw_color(color);
    }
    void Window::clear()
    {
        _renderer.clear();
    }
}  // namespace linden::sdl2