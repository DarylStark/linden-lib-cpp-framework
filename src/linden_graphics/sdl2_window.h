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

    public:
        SDL2Window(const std::string& title, Position position, Size size,
                   uint32_t flags);
        ~SDL2Window();

        // Retrievers
        SDL_Window* get_window_handle() const;
    };
}  // namespace linden::graphics