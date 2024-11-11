#pragma once
#include <SDL2/SDL.h>

#include "models.h"
#include "sdl2_renderer.h"

// TODO: Mulitple header and CPP files instead of three classes in one?

namespace linden::graphics
{
    enum class TextureAccess
    {
        STATIC = 0,
        STREAMING = 1,
        TARGET = 2
    };

    class SDL2Texture
    {
    protected:
        SDL_Texture* _texture;

    public:
        SDL2Texture(const SDL2Renderer& renderer, TextureAccess access,
                    Size size);
        ~SDL2Texture();

        // Get native SDL2 handle
        SDL_Texture* get_sdl2_texture_handle() const;
    };

    class SDL2StaticTexture : public SDL2Texture
    {
    private:
        SDL_Texture* _texture;

    public:
        SDL2StaticTexture(const SDL2Renderer& renderer, Size size);
    };

    class SDL2StreamingTexture : public SDL2Texture
    {
    private:
        SDL_Texture* _texture;
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

    class SDL2TargetTexture : public SDL2Texture
    {
    private:
        SDL_Texture* _texture;

    public:
        SDL2TargetTexture(const SDL2Renderer& renderer, Size size);
    };
}  // namespace linden::graphics