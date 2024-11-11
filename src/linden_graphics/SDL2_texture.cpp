#include "sdl2_texture.h"

namespace linden::graphics
{
    SDL2Texture::SDL2Texture(const SDL2Renderer& renderer, TextureAccess access,
                             Size size)
    {
        _texture = SDL_CreateTexture(
            renderer.get_sdl2_renderer_handle(), SDL_PIXELFORMAT_ARGB8888,
            static_cast<int>(access), size.width, size.height);
        SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
        // TODO: Exception
    }

    SDL2Texture::~SDL2Texture()
    {
        if (_texture != nullptr) SDL_DestroyTexture(_texture);
    }

    SDL_Texture* SDL2Texture::get_sdl2_texture_handle() const
    {
        return _texture;
    }

    void SDL2Texture::set_alpha(uint8_t alpha)
    {
        SDL_SetTextureAlphaMod(_texture, alpha);
    }

    SDL2StaticTexture::SDL2StaticTexture(const SDL2Renderer& renderer,
                                         Size size)
        : SDL2Texture(renderer, TextureAccess::STATIC, size)
    {
    }

    SDL2StreamingTexture::SDL2StreamingTexture(const SDL2Renderer& renderer,
                                               Size size)
        : SDL2Texture(renderer, TextureAccess::STREAMING, size)
    {
    }

    void SDL2StreamingTexture::lock()
    {
        if (SDL_LockTexture(_texture, NULL, &_pixels, &_pitch) < 0)
        {
            // TODO: Exception
            return;
        }
        _locked = true;
    }

    void SDL2StreamingTexture::unlock()
    {
        SDL_UnlockTexture(_texture);
        _locked = false;
    }

    bool SDL2StreamingTexture::is_locked() const
    {
        return _locked;
    }

    void SDL2StreamingTexture::set_pixel(Position position, Color color)
    {
        if (!_locked)
        {
            // TODO: Exception
            return;
        }

        uint32_t* pixel_data = static_cast<uint32_t*>(_pixels);

        pixel_data[position.y * (_pitch / 4) + position.x] =
            (color.a << 24) | (color.r << 16) | (color.g << 8) | color.b;
        asm("nop");
    }

    void* SDL2StreamingTexture::get_pixels() const
    {
        return _pixels;
    }

    int SDL2StreamingTexture::get_pitch() const
    {
        return _pitch;
    }

    SDL2TargetTexture::SDL2TargetTexture(const SDL2Renderer& renderer,
                                         Size size)
        : SDL2Texture(renderer, TextureAccess::TARGET, size)

    {
    }
}  // namespace linden::graphics