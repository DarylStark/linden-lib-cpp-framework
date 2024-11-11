#include "sdl2_renderer.h"

#include <SDL2/SDL.h>

namespace linden::graphics
{
    SDL2Renderer::SDL2Renderer(SDL_Window* window_handle)
    {
        // TODO: Make the flags configurable
        _renderer_handle =
            SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawBlendMode(_renderer_handle, SDL_BLENDMODE_BLEND);
    }

    SDL2Renderer::~SDL2Renderer()
    {
        if (_renderer_handle) SDL_DestroyRenderer(_renderer_handle);
    }

    SDL_Renderer* SDL2Renderer::get_sdl2_renderer_handle() const
    {
        return _renderer_handle;
    }

    void SDL2Renderer::clear()
    {
        SDL_RenderClear(_renderer_handle);
    }

    void SDL2Renderer::clear(Color color)
    {
        SDL_SetRenderDrawColor(_renderer_handle, color.r, color.g, color.b,
                               color.a);
        SDL_RenderClear(_renderer_handle);
    }
};  // namespace linden::graphics