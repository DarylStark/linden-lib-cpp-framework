#pragma once
#include "../types.h"
#include "sdl2_window.h"

namespace linden::sdl2
{
    class Context
    {
    public:
        Context();
        ~Context();

        // Object management
        void cleanup();

        // Retrieve objects
        Window create_window(const std::string& title,
                             linden::Position position, linden::Size size);
    };
}  // namespace linden::sdl2