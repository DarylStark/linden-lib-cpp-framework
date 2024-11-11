#pragma once

#include "sdl2_texture.h"

namespace linden::graphics
{
    class SDL2StreamingTexture : public SDL2Texture
    {
    private:
        void* _pixels;
        int _pitch;
        bool _locked = false;

    public:
        SDL2StreamingTexture(const SDL2Renderer& renderer, Size size);

        // Locking to write to the texture
        void lock();
        void unlock();
        bool is_locked() const;

        // Set pixel
        void set_pixel(Position position, Color color);

        // Pixel data
        void* get_pixels() const;
        int get_pitch() const;
    };
}  // namespace linden::graphics