#pragma once
#include "models.h"
#include "sdl2_window.h"

namespace linden::graphics
{
    class SDL2
    {
    public:
        SDL2();
        ~SDL2();

        // Retrieve objects
        SDL2Window create_window(const std::string& title, Position position,
                                 Size size);
    };
}  // namespace linden::graphics