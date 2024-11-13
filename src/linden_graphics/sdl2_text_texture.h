#pragma once
#include "sdl2_font.h"
#include "sdl2_renderer.h"
#include "sdl2_texture.h"

namespace linden::graphics
{
    class SDL2TextTexture : public SDL2Texture
    {
    private:
        std::string _text;
        SDL2Font& _font;
        Color _color;

        void _update_texture();

    public:
        SDL2TextTexture(const SDL2Renderer& renderer, const std::string& text,
                        SDL2Font& font, Color color);

        void set_text(const std::string& text);
    };
}  // namespace linden::graphics