#include "sdl2.h"

#include <SDL2/SDL.h>

#include "sdl2_window.h"

namespace linden::graphics
{
    SDL2::SDL2()
    {
        int init = SDL_Init(SDL_INIT_VIDEO);
        if (init != 0)
        {
            // TODO: Throw exception
        }
    }

    SDL2::~SDL2()
    {
        SDL_Quit();
    }

    SDL2Window SDL2::create_window(const std::string& title, Position position,
                                   Size size)
    {
        // TODO: Make the flags configurable
        // TODO: This is copied. That might be a badddd idea
        SDL2Window window(title, position, size, SDL_WINDOW_SHOWN);
        window.add_window_renderer();
        return window;
    }
}  // namespace linden::graphics