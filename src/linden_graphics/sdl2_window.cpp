#include "sdl2_window.h"

namespace linden::graphics
{
    SDL2Window::SDL2Window(const std::string& title, Position position,
                           Size size, uint32_t flags)
    {
        _window_handle = SDL_CreateWindow(title.c_str(), position.x, position.y,
                                          size.width, size.height, flags);
        return;
    }

    SDL2Window::~SDL2Window()
    {
        _renderer
            .reset();  // Makes sure the renderer is destroyed before the window
        if (_window_handle) SDL_DestroyWindow(_window_handle);
    }

    void SDL2Window::add_window_renderer()
    {
        // TODO: Make the flags configurable
        if (!_renderer)
            _renderer = std::make_shared<SDL2Renderer>(_window_handle);
    }

    Size SDL2Window::get_window_size() const
    {
        int width, height;
        SDL_GetWindowSize(_window_handle, &width, &height);
        return {width, height};
    }

    Size SDL2Window::get_drawable_size() const
    {
        int width, height;
        SDL_GL_GetDrawableSize(_window_handle, &width, &height);
        return {width, height};
    }

    Position SDL2Window::get_window_position() const
    {
        int x, y;
        SDL_GetWindowPosition(_window_handle, &x, &y);
        return {x, y};
    }

    SDL_Window* SDL2Window::get_sdl2_window_handle() const
    {
        return _window_handle;
    }

    std::shared_ptr<SDL2Renderer> SDL2Window::get_renderer() const
    {
        return _renderer;
    }
}  // namespace linden::graphics