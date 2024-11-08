#include "sdl2_window.h"

namespace linden::graphics
{
    SDL2Window::SDL2Window(const std::string& title, Position position,
                           Size size, uint32_t flags)
    {
        _window_handle = SDL_CreateWindow(title.c_str(), position.x, position.y,
                                          size.width, size.height, flags);
    }

    SDL2Window::~SDL2Window()
    {
        if (_window_handle) SDL_DestroyWindow(_window_handle);
    }

    SDL_Window* SDL2Window::get_window_handle() const
    {
        return _window_handle;
    }
}  // namespace linden::graphics