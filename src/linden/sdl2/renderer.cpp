#include "renderer.h"

#include "exceptions.h"

namespace linden::sdl2
{
    Renderer::Renderer(SDL_Window* window_handle)
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
}  // namespace linden::sdl2