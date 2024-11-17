#include "frame_rate_limiter.h"

#include <iostream>
#include <thread>

namespace linden::utils
{
    FrameRateLimiter::FrameRateLimiter(const uint32_t target_fps)
        : _target_fps(target_fps)
    {
        _target_frame_duration = std::chrono::microseconds(0);

        if (_target_fps)
            _target_frame_duration =
                std::chrono::microseconds(1000000 / _target_fps);
        start();
    }

    FrameRateLimiter::~FrameRateLimiter()
    {
        stop();
    }

    void FrameRateLimiter::start()
    {
        _frame_start_time = std::chrono::high_resolution_clock::now();
    }

    void FrameRateLimiter::stop()
    {
        _frame_end_time = std::chrono::high_resolution_clock::now();
        _frame_processing_time =
            std::chrono::duration_cast<std::chrono::microseconds>(
                _frame_end_time - _frame_start_time);
        delay();
    }

    void FrameRateLimiter::delay()
    {
        if (_target_fps == 0) return;

        // Calculate the delay time
        _delay_time = _target_frame_duration - _frame_processing_time;
        std::chrono::microseconds local_delay_time = _delay_time;

        if (_delay_time.count() > 0)
        {
            if (local_delay_time.count() >
                1000)  // Sleep only if delay time is significant
            {
                const auto sleeptime =
                    local_delay_time - std::chrono::microseconds(1000);
                std::this_thread::sleep_for(local_delay_time -
                                            std::chrono::microseconds(1000));
                local_delay_time = std::chrono::microseconds(
                    1000);  // Set remaining delay time for busy-wait
            }

            // Busy-wait for the remaining time to achieve higher precision
            auto busy_wait_start = std::chrono::high_resolution_clock::now();
            while (std::chrono::duration_cast<std::chrono::microseconds>(
                       std::chrono::high_resolution_clock::now() -
                       busy_wait_start) < local_delay_time)
            {
                // Busy-wait loop
            }
        }
    }
}  // namespace linden::utils