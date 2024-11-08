#pragma once

#include "sdl2_renderer.h"

#include <SDL2/SDL.h>

namespace linden::graphics
{
    SDL2Renderer::SDL2Renderer(SDL_Window* window_handle)
    {
        // TODO: Make the flags configurable
        _renderer_handle =
            SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED);
    }

    SDL2Renderer::~SDL2Renderer()
    {
        if (_renderer_handle) SDL_DestroyRenderer(_renderer_handle);
    }

    SDL_Renderer* SDL2Renderer::get_sdl2_renderer_handle() const
    {
        return _renderer_handle;
    }
};  // namespace linden::graphics