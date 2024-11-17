#pragma once

#include <exception>
#include <string>

namespace linden
{
    enum class ExceptionSeverity
    {
        WARNING,
        ERROR,
        FATAL
    };

    class Exception : public std::exception
    {
    private:
        const ExceptionSeverity _severity;
        const std::string _message;

    public:
        Exception(const ExceptionSeverity& _severity,
                  const std::string& message);

        const ExceptionSeverity Exception::severity() const noexcept;
        const char* what() const noexcept override;
    };
}  // namespace linden