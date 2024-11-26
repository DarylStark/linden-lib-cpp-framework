#include "sprite_sheet.h"

namespace linden::sdl2
{
    SpriteSheet::SpriteSheet(Renderer& renderer_handle, const std::string& path)
        : _renderer_handle(renderer_handle), _sprite(renderer_handle, path)
    {
    }

    void SpriteSheet::set_sprite(const std::string& name,
                                 linden::Position position, linden::Size size)
    {
        _sprites.emplace(name, SpriteFragment(_sprite, position, size));
    }

    SpriteFragment& SpriteSheet::get_sprite(const std::string& name)
    {
        return _sprites.at(name);
    }
}  // namespace linden::sdl2