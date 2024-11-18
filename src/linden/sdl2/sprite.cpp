#include "sprite.h"

namespace linden::sdl2
{
    Sprite::Sprite(Renderer& renderer_handle)
        : _renderer_handle(renderer_handle), _texture_handle(nullptr)
    {
    }

    Sprite::~Sprite()
    {
        cleanup();
    }

    void Sprite::cleanup()
    {
        if (_texture_handle != nullptr) SDL_DestroyTexture(_texture_handle);
    }

    void Sprite::render(const RenderConfig& configuration)
    {
        // Stop if there is nothing to do
        if (!_texture_handle) return;
        if (!configuration.active) return;

        SDL_Rect dst;
        dst.x = configuration.destination.position.x;
        dst.y = configuration.destination.position.y;
        dst.w = configuration.destination.size.width;
        dst.h = configuration.destination.size.height;

        SDL_Rect src;
        src.x = configuration.source.position.x;
        src.y = configuration.source.position.y;
        src.w = configuration.source.size.width;
        src.h = configuration.source.size.height;

        uint32_t flip = 0;
        if (configuration.rotation.flip_horizontal) flip |= SDL_FLIP_HORIZONTAL;
        if (configuration.rotation.flip_vertical) flip |= SDL_FLIP_VERTICAL;

        SDL_Point center = {configuration.rotation.center.x,
                            configuration.rotation.center.y};

        SDL_RenderCopyEx(_renderer_handle.get_sdl2_renderer_handle(),
                         _texture_handle, &src, &dst,
                         configuration.rotation.angle, &center,
                         static_cast<SDL_RendererFlip>(flip));
    }

    Renderer& Sprite::get_renderer_handle() const
    {
        return _renderer_handle;
    }

    SDL_Texture* Sprite::get_sdl2_texture_handle() const
    {
        return _texture_handle;
    }
}  // namespace linden::sdl2