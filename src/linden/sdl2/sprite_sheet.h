#pragma once

#include <map>
#include <string>

#include "../types.h"
#include "image_sprite.h"
#include "renderer.h"
#include "sprite_fragment.h"

namespace linden::sdl2
{
    class SpriteSheet
    {
    private:
        Renderer& _renderer_handle;
        ImageSprite _sprite;
        std::map<std::string, SpriteFragment> _sprites;

    public:
        SpriteSheet(Renderer& renderer_handle, const std::string& path);
        void set_sprite(const std::string& name, linden::Position position,
                        linden::Size size);
        SpriteFragment& get_sprite(const std::string& name);
    };
}  // namespace linden::sdl2