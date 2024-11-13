#pragma once

#include <SDL_ttf.h>

#include <string>

namespace linden::graphics
{
    class SDL2Font
    {
    private:
        TTF_Font* _font;

    public:
        SDL2Font(const std::string& pat, int size);
        ~SDL2Font();

        // Set the size of the font
        void set_size(int size);

        // Get the SDL2 objects
        TTF_Font* get_sdl2_font_handle() const;
    };
}  // namespace linden::graphics