#include "renderer.h"

#include "exceptions.h"

namespace linden::sdl2
{
    Renderer::Renderer(SDL_Window* window_handle) : _renderer_handle(nullptr)
    {
        initialize(window_handle);
    }

    Renderer::~Renderer()
    {
        cleanup();
    }

    void Renderer::cleanup()
    {
        if (_renderer_handle) SDL_DestroyRenderer(_renderer_handle);
    }

    void Renderer::initialize(SDL_Window* window_handle)
    {
        if (_renderer_handle) return;

        // TODO: Make the flags configurable
        _renderer_handle =
            SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED);

        if (!_renderer_handle)
            throw SDL2RendererCreationException(
                "Failed to create SDL2 renderer: " +
                std::string(SDL_GetError()));
    }

    SDL_Renderer* Renderer::get_sdl2_renderer_handle() const
    {
        return _renderer_handle;
    }

    void Renderer::present()
    {
        SDL_RenderPresent(_renderer_handle);
    }

    void Renderer::set_draw_color(const linden::Color& color)
    {
        SDL_SetRenderDrawColor(_renderer_handle, color.red, color.green,
                               color.blue, color.alpha);
    }

    void Renderer::clear()
    {
        SDL_RenderClear(_renderer_handle);
    }

    void Renderer::reset_target()
    {
        SDL_SetRenderTarget(_renderer_handle, nullptr);
    }
}  // namespace linden::sdl2