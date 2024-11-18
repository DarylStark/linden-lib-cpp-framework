#include "renderable.h"

namespace linden::sdl2
{
    RenderConfig& Renderable::update_render_config(
        RenderConfig& configuration) const
    {
        if (configuration.source.size.width == 0 &&
            configuration.source.size.height == 0)
            configuration.source.size = get_size();

        if (configuration.destination.size.width == 0 &&
            configuration.destination.size.height == 0)
            configuration.destination.size = get_size();

        return configuration;
    }
}  // namespace linden::sdl2