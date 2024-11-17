#include "context.h"

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include <utility>

#include "../types.h"
#include "exceptions.h"
#include "window.h"

namespace linden::sdl2
{
    Context::Context()
    {
        // Initialize SDL2
        int init_sdl = SDL_Init(SDL_INIT_VIDEO);
        if (init_sdl != 0) throw SDL2InitException("Failed to initialize SDL2");

        // Initialize SDL2_ttf
        int init_ttf = TTF_Init();
        if (init_ttf != 0)
            throw SDL2TTFInitException("Failed to initialize SDL2_ttf");
    }

    Context::~Context()
    {
        cleanup();
    }

    void Context::cleanup()
    {
        TTF_Quit();
        SDL_Quit();
    }

    Window Context::create_window(const std::string& title,
                                  linden::Position position, linden::Size size)
    {
        // TODO: Make the flags configurable
        Window window(title, position, size, SDL_WINDOW_SHOWN);

        return std::move(window);
    }
}  // namespace linden::sdl2