#pragma once

#pragma once

#include "../exceptions.h"

namespace linden::sdl2
{
    class SDL2Exception : public linden::Exception
    {
    public:
        SDL2Exception(const ExceptionSeverity& _severity,
                      const std::string& message);
    };

    class SDL2InitException : public SDL2Exception
    {
    public:
        SDL2InitException(const std::string& message);
    };

    class SDL2TTFInitException : public SDL2Exception
    {
    public:
        SDL2TTFInitException(const std::string& message);
    };

    class SDL2WindowCreationException : public SDL2Exception
    {
    public:
        SDL2WindowCreationException(const std::string& message);
    };

    class SDL2RendererCreationException : public SDL2Exception
    {
    public:
        SDL2RendererCreationException(const std::string& message);
    };
}  // namespace linden::sdl2