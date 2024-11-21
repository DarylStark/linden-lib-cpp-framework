#pragma once

#include <vector>

#include "../types.h"
#include "renderable.h"
#include "renderer.h"
#include "target_sprite.h"

namespace linden::sdl2
{

    class TileGrid : public Renderable
    {
    private:
        Renderer& _renderer;
        std::vector<TargetSprite> _tiles;
        linden::Size _grid_size;
        linden::Size _tile_size;
        uint32_t _cols;
        uint32_t _rows;

    public:
        TileGrid(Renderer& renderer, linden::Size grid_size,
                 linden::Size tile_size);

        // Render methods
        void render(RenderConfig configuration);
        linden::Size get_size() const;

        // Retrieve information
        uint32_t get_tile_count() const;
        uint32_t get_row_count() const;
        uint32_t get_col_count() const;
        uint32_t get_tile_index(uint32_t col, uint32_t row) const;

        // Creation of sprite contents
        void fill(const linden::Color& color);
        void fill(const linden::Color& color, uint32_t col, uint32_t row);
    };
}  // namespace linden::sdl2