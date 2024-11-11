#include "sdl2_renderer.h"

#include <SDL2/SDL.h>

#include "sdl2_texture.h"

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

    void SDL2Renderer::render()
    {
        SDL_RenderPresent(_renderer_handle);
    }

    void SDL2Renderer::render_texture(const SDL2Texture& texture,
                                      TextureRenderOptions options)
    {
        SDL_Rect rect;
        rect.x = options.position.x;
        rect.y = options.position.y;
        rect.w = options.size.width;
        rect.h = options.size.height;

        SDL_RenderCopyEx(_renderer_handle, texture.get_sdl2_texture_handle(),
                         nullptr, &rect, options.angle, nullptr, SDL_FLIP_NONE);
    }
};  // namespace linden::graphics