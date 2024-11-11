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

    void SDL2Renderer::render_texture(const SDL2Texture& texture)
    {
        SDL_RenderCopy(_renderer_handle, texture.get_sdl2_texture_handle(),
                       nullptr, nullptr);
    }

    void SDL2Renderer::render_texture(const SDL2Texture& texture,
                                      TextureRenderOptions options)
    {
        if (!options.active) return;

        if (options.size.width == 0)
            options.size.width = texture.get_size().width;
        if (options.size.height == 0)
            options.size.height = texture.get_size().height;
        options.size.width *= options.scale;
        options.size.height *= options.scale;
        options.rotation_center.x *= options.scale;
        options.rotation_center.y *= options.scale;

        SDL_Rect rect;
        rect.x = options.position.x;
        rect.y = options.position.y;
        rect.w = options.size.width;
        rect.h = options.size.height;

        uint32_t flip = 0;
        if (options.flip_horizontal) flip |= SDL_FLIP_HORIZONTAL;
        if (options.flip_vertical) flip |= SDL_FLIP_VERTICAL;

        SDL_Point center = {options.rotation_center.x,
                            options.rotation_center.y};
        SDL_RenderCopyEx(_renderer_handle, texture.get_sdl2_texture_handle(),
                         nullptr, &rect, options.angle, &center,
                         static_cast<SDL_RendererFlip>(flip));
    }
};  // namespace linden::graphics