#include "scoped_target.h"

namespace linden::sdl2
{
    ScopedTarget::ScopedTarget(const TargetSprite& target) : _target(target)
    {
        start();
    }

    ScopedTarget::~ScopedTarget()
    {
        stop();
    }

    void ScopedTarget::start()
    {
        SDL_SetRenderTarget(
            _target.get_renderer_handle().get_sdl2_renderer_handle(),
            _target.get_sdl2_texture_handle());
    }

    void ScopedTarget::stop()
    {
        _target.get_renderer_handle().reset_target();
    }
}  // namespace linden::sdl2