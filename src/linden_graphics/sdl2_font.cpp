#include "sdl2_font.h"

namespace linden::graphics
{
    SDL2Font::SDL2Font(const std::string& path, int size)
    {
        _font = TTF_OpenFont(path.c_str(), size);
        if (_font == nullptr)
        {
            // TODO: Exception
        }
    }

    SDL2Font::~SDL2Font()
    {
        TTF_CloseFont(_font);
    }

    void SDL2Font::set_size(int size)
    {
        if (_font) TTF_SetFontSize(_font, size);
    }

    TTF_Font* SDL2Font::get_sdl2_font_handle() const
    {
        return _font;
    }
}  // namespace linden::graphics