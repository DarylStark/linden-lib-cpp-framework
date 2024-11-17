#include "exceptions.h"

namespace linden::sdl2
{
    SDL2Exception::SDL2Exception(const ExceptionSeverity& severity,
                                 const std::string& message)
        : linden::Exception(severity, message)
    {
    }

    SDL2InitException::SDL2InitException(const std::string& message)
        : SDL2Exception(linden::ExceptionSeverity::FATAL, message)
    {
    }

    SDL2TTFInitException::SDL2TTFInitException(const std::string& message)
        : SDL2Exception(linden::ExceptionSeverity::FATAL, message)
    {
    }

    SDL2WindowCreationException::SDL2WindowCreationException(
        const std::string& message)
        : SDL2Exception(linden::ExceptionSeverity::FATAL, message)
    {
    }

    SDL2RendererCreationException::SDL2RendererCreationException(
        const std::string& message)
        : SDL2Exception(linden::ExceptionSeverity::FATAL, message)
    {
    }
}  // namespace linden::sdl2