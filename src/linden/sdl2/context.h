#pragma once
#include "../types.h"
#include "window.h"

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

        // Delay
        void delay(uint32_t milliseconds);
    };
}  // namespace linden::sdl2