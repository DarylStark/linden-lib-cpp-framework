#include "sdl2_static_texture.h"

namespace linden::graphics
{
    SDL2StaticTexture::SDL2StaticTexture(const SDL2Renderer& renderer,
                                         Size size)
        : SDL2Texture(renderer, TextureAccess::STATIC, size)
    {
    }
}  // namespace linden::graphics