#include "sdl2.h"

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include "sdl2_window.h"

namespace linden::graphics
{
    SDL2::SDL2()
    {
        int init_sdl = SDL_Init(SDL_INIT_VIDEO);
        if (init_sdl != 0)
        {
            // TODO: Throw exception
        }

        int init_ttf = TTF_Init();
        if (init_ttf != 0)
        {
            // TODO: Throw exception
        }
    }

    SDL2::~SDL2()
    {
        TTF_Quit();
        SDL_Quit();
    }

    SDL2Window SDL2::create_window(const std::string& title, Position position,
                                   Size size)
    {
        // TODO: Make the flags configurable
        // TODO: This is copied in the return value. That might be a bad idea.
        SDL2Window window(title, position, size, SDL_WINDOW_SHOWN);
        window.add_window_renderer();
        return window;
    }
}  // namespace linden::graphics