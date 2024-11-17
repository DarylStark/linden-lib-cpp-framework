#pragma once

#include <chrono>

namespace linden::utils
{
    class FrameRateLimiter
    {
    private:
        uint32_t _target_fps;
        std::chrono::time_point<std::chrono::high_resolution_clock>
            _frame_start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock>
            _frame_end_time;
        std::chrono::microseconds _target_frame_duration;
        std::chrono::microseconds _frame_processing_time;
        std::chrono::microseconds _delay_time;

    public:
        FrameRateLimiter(const uint32_t target_fps);
        ~FrameRateLimiter();
        void start();
        void stop();
        virtual void delay();
    };
}  // namespace linden::utils