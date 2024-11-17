#include "scoped_timer.h"

#include <iomanip>
#include <iostream>

namespace linden::utils
{
    ScopedTimer::ScopedTimer()
    {
        _frame_start_time = std::chrono::high_resolution_clock::now();
    }

    ScopedTimer::~ScopedTimer()
    {
        _frame_end_time = std::chrono::high_resolution_clock::now();
        int64_t frame_duration =
            std::chrono::duration_cast<std::chrono::microseconds>(
                _frame_end_time - _frame_start_time)
                .count();

        double fps = -1;
        if (frame_duration > 0) fps = 1000000. / frame_duration;

        std::cout << "Duration: " << std::setw(9) << std::setfill('.')
                  << frame_duration << "us >> ";
        std::cout << "FPS: " << std::fixed << std::setprecision(4) << fps
                  << " FPS";
        std::cout << '\n';
    }
}  // namespace linden::utils