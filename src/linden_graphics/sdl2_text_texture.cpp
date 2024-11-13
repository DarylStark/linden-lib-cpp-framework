#include "sdl2_text_texture.h"

namespace linden::graphics
{
    SDL2TextTexture::SDL2TextTexture(const SDL2Renderer& renderer,
                                     const std::string& text, SDL2Font& font,
                                     Color color)
        : SDL2Texture(renderer), _font(font), _text(text), _color(color)
    {
        _update_texture();
    }

    void SDL2TextTexture::_update_texture()
    {
        SDL_Surface* surface = TTF_RenderUTF8_Blended(
            _font.get_sdl2_font_handle(), _text.c_str(),
            SDL_Color({_color.r, _color.g, _color.b, _color.a}));
        _texture = SDL_CreateTextureFromSurface(
            _renderer.get_sdl2_renderer_handle(), surface);
    }

    void SDL2TextTexture::set_text(const std::string& text)
    {
        _text = text;
        _update_texture();
    }
}  // namespace linden::graphics