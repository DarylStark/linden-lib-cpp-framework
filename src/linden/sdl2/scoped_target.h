#pragma once

#include "renderer.h"
#include "target_sprite.h"

namespace linden::sdl2
{
    class ScopedTarget
    {
    private:
        const TargetSprite& _target;

    public:
        ScopedTarget(const TargetSprite& target);
        ~ScopedTarget();

        // Scope management
        void start();
        void stop();
    };
}  // namespace linden::sdl2