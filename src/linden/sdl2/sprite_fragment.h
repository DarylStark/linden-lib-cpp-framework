#pragma once

#include "../types.h"
#include "redenerable.h"
#include "sprite.h"

namespace linden::sdl2
{
    class SpriteFragment : public Renderable
    {
    public:
        SpriteFragment(Sprite& sprite, linden::Position position,
                       linden::Size size);
        void render(const RenderConfig& configuration) override;

    private:
        Sprite& _source_sprite;
        linden::Position _position;
        linden::Size _size;
    };
}  // namespace linden::sdl2