#pragma once
#include <SDL2/SDL.h>

#include <memory>
#include <string>

#include "models.h"

// Forward declaration of SDL2Texture
namespace linden::graphics
{
    class SDL2Renderer;
}

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
        const SDL2Renderer& _renderer;
        SDL_Texture* _texture;

    public:
        SDL2Texture(const SDL2Renderer& renderer);
        SDL2Texture(const SDL2Renderer& renderer, TextureAccess access,
                    Size size);
        ~SDL2Texture();

        // Get native SDL2 handle
        SDL_Texture* get_sdl2_texture_handle() const;

        // Texture altering
        void set_alpha(uint8_t alpha);

        // Get texture information
        Size get_size() const;

        // Subtextures
        std::shared_ptr<SDL2Texture> create_sub_texture(Position position,
                                                        Size size) const;
    };

    class SDL2StaticTexture : public SDL2Texture
    {
    public:
        SDL2StaticTexture(const SDL2Renderer& renderer, Size size);
    };

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

    class SDL2TargetTexture : public SDL2Texture
    {
    public:
        SDL2TargetTexture(const SDL2Renderer& renderer, Size size);
    };

    class SDL2ImageTexture : public SDL2Texture
    {
    public:
        SDL2ImageTexture(const SDL2Renderer& renderer, const std::string& path);
    };

}  // namespace linden::graphics