#include "sdl2_texture.h"

#include <SDL_image.h>

#include "sdl2_renderer.h"

namespace linden::graphics
{
    SDL2Texture::SDL2Texture(const SDL2Renderer& renderer)
        : _texture(nullptr), _renderer(renderer)
    {
    }

    SDL2Texture::SDL2Texture(const SDL2Renderer& renderer, TextureAccess access,
                             Size size)
        : _renderer(renderer)
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

    Size SDL2Texture::get_size() const
    {
        int width, height;
        SDL_QueryTexture(_texture, nullptr, nullptr, &width, &height);
        return {width, height};
    }

    std::shared_ptr<SDL2Texture> SDL2Texture::create_sub_texture(
        Position position, Size size) const
    {
        std::shared_ptr<SDL2Texture> sub_texture =
            std::make_shared<SDL2TargetTexture>(_renderer, size);

        SDL_Texture* sub_texture_handle =
            sub_texture->get_sdl2_texture_handle();

        SDL_Rect rect = {position.x, position.y, size.width, size.height};
        int32_t srt_r = SDL_SetRenderTarget(
            _renderer.get_sdl2_renderer_handle(), sub_texture_handle);
        int32_t src_r = SDL_RenderCopy(_renderer.get_sdl2_renderer_handle(),
                                       _texture, &rect, nullptr);
        int32_t srt2_r =
            SDL_SetRenderTarget(_renderer.get_sdl2_renderer_handle(), nullptr);

        return sub_texture;
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

    SDL2ImageTexture::SDL2ImageTexture(const SDL2Renderer& renderer,
                                       const std::string& path)
        : SDL2Texture(renderer)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        _texture = SDL_CreateTextureFromSurface(
            renderer.get_sdl2_renderer_handle(), surface);
        SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
        SDL_FreeSurface(surface);
        // TODO: Exception
    }
}  // namespace linden::graphics