#pragma once

#include "exceptions.h"

namespace linden
{
    Exception::Exception(const ExceptionSeverity& severity,
                         const std::string& message)
        : _severity(severity), _message(message)
    {
    }

    const ExceptionSeverity Exception::severity() const noexcept
    {
        return _severity;
    }

    const char* Exception::what() const noexcept
    {
        return _message.c_str();
    }
}  // namespace linden