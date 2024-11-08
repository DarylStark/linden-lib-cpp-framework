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
        return SDL2Window(title, position, size, SDL_WINDOW_SHOWN);
    }
}  // namespace linden::graphics