#pragma once

#include "../types.h"
#include "redenerable.h"
#include "sprite.h"

namespace linden::sdl2
{
    class SpriteFragment : public Renderable
    {
    private:
        Sprite& _source_sprite;
        linden::Position _position;
        linden::Size _size;

    public:
        SpriteFragment(Sprite& sprite, linden::Position position,
                       linden::Size size);
        void render(RenderConfig configuration) override;

        // Sprite information
        virtual linden::Size get_size() const;
    };
}  // namespace linden::sdl2