#include "tile_grid.h"

#include "scoped_target.h"

namespace linden::sdl2
{
    TileGrid::TileGrid(Renderer &renderer, linden::Size grid_size,
                       linden::Size tile_size)
        : _renderer(renderer), _grid_size(grid_size), _tile_size(tile_size)
    {
        _cols = (grid_size.width + tile_size.width - 1) / tile_size.width;
        _rows = (grid_size.height + tile_size.height - 1) / tile_size.height;
        _tiles.reserve(_cols * _rows);
        for (uint32_t i = 0; i < _cols * _rows; i++)
        {
            linden::Size size = tile_size;

            // Last column
            if (i % _cols == _cols - 1)
            {
                size.width = grid_size.width % tile_size.width;
                if (size.width == 0) size.width = tile_size.width;
            }

            // Last row
            if (i >= _cols * (_rows - 1))
            {
                size.height = grid_size.height % tile_size.height;
                if (size.height == 0) size.height = tile_size.height;
            }

            _tiles.emplace_back(renderer, size);
        }
    }

    void TileGrid::render(RenderConfig configuration)
    {
        for (uint32_t row = 0; row < _rows; row++)
        {
            for (uint32_t col = 0; col < _cols; col++)
            {
                auto &tile = _tiles[get_tile_index(col, row)];

                RenderConfig tile_configuration;
                tile_configuration.destination.size = tile.get_size();
                tile_configuration.source.size = tile.get_size();

                tile_configuration.destination.position = {
                    static_cast<int32_t>((col * _tile_size.width) +
                                         configuration.destination.position.x),
                    static_cast<int32_t>((row * _tile_size.height) +
                                         configuration.destination.position.y)};

                // TODO: only render if visible

                tile.render(tile_configuration);
            }
        }
    }

    linden::Size TileGrid::get_size() const
    {
        return _grid_size;
    }

    uint32_t TileGrid::get_tile_count() const
    {
        return _tiles.size();
    }

    uint32_t TileGrid::get_row_count() const
    {
        return _rows;
    }

    uint32_t TileGrid::get_col_count() const
    {
        return _cols;
    }

    uint32_t TileGrid::get_tile_index(uint32_t col, uint32_t row) const
    {
        return row * _cols + col;
    }

    void TileGrid::fill(const linden::Color &color)
    {
        for (auto &tile : _tiles)
            tile.fill(color);
    }

    void TileGrid::fill(const linden::Color &color, uint32_t col, uint32_t row)
    {
        uint32_t tile_index = get_tile_index(col, row);
        if (tile_index >= _tiles.size()) return;
        _tiles[tile_index].fill(color);
    }

    void TileGrid::add_renderable(Renderable &renderable,
                                  RenderConfig render_config)
    {
        if (render_config.destination.position.x >= _grid_size.width ||
            render_config.destination.position.y >= _grid_size.height)
            return;

        renderable.update_render_config(render_config);

        // Find the tiles to render it to
        uint32_t start_col =
            render_config.destination.position.x / _tile_size.width;
        uint32_t end_col = (render_config.destination.position.x +
                            render_config.destination.size.width) /
                           _tile_size.width;
        uint32_t start_row =
            render_config.destination.position.y / _tile_size.height;
        uint32_t end_row = (render_config.destination.position.y +
                            render_config.destination.size.height) /
                           _tile_size.height;

        // Loop over the tiles and render the texture to it
        for (uint32_t y = start_row; y <= end_row; y++)
        {
            for (uint32_t x = start_col; x <= end_col; x++)
            {
                // Calculate X in tile
                int32_t tile_x = render_config.destination.position.x -
                                 (start_col * _tile_size.width);

                if (x > start_col)
                    tile_x = -((_tile_size.width * x) -
                               render_config.destination.position.x);

                // Calculate Y in tile
                int32_t tile_y = render_config.destination.position.y -
                                 (start_row * _tile_size.height);

                if (y > start_row)
                    tile_y = -((_tile_size.height * y) -
                               render_config.destination.position.y);

                ScopedTarget target(_tiles[get_tile_index(x, y)]);
                renderable.render(
                    {.destination = {.position = {.x = tile_x, .y = tile_y}}});
            }
        }
    }
}  // namespace linden::sdl2