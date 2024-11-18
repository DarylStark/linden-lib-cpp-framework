#include "sprite_fragment.h"

namespace linden::sdl2
{
    SpriteFragment::SpriteFragment(Sprite& sprite, linden::Position position,
                                   linden::Size size)
        : _source_sprite(sprite), _position(position), _size(size)
    {
    }

    void SpriteFragment::render(const RenderConfig& configuration)
    {
        linden::Size new_size = configuration.source.size;
        if (configuration.source.position.x + configuration.source.size.width >
            _size.width)
        {
            new_size.width = _size.width - configuration.source.position.x;
        }

        if (configuration.source.position.y + configuration.source.size.height >
            _size.height)
        {
            new_size.height = _size.height - configuration.source.position.y;
        }

        _source_sprite.render({
            .destination = configuration.destination,
            .source = {.position =
                           {
                               _position.x + configuration.source.position.x,
                               _position.y + configuration.source.position.y,
                           },
                       .size = new_size},
            .rotation = configuration.rotation,
        });
    }
}  // namespace linden::sdl2