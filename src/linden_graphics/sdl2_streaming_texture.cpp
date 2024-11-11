#include "sdl2_streaming_texture.h"

namespace linden::graphics
{
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
}  // namespace linden::graphics