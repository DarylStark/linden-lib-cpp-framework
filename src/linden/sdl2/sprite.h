#pragma once
#include <SDL2/SDL.h>

#include "redenerable.h"
#include "renderer.h"

namespace linden::sdl2
{
    class Sprite : public Renderable
    {
    protected:
        Renderer& _renderer_handle;
        SDL_Texture* _texture_handle;

    public:
        Sprite(Renderer& renderer_handle);
        virtual ~Sprite() = 0;

        // Object management
        void cleanup();

        // Render methods
        virtual void render(const RenderConfig& configuration) override;

        // Retriever for our objects
        Renderer& get_renderer_handle() const;

        // Retrievers for SDL2 handles
        SDL_Texture* get_sdl2_texture_handle() const;
    };
}  // namespace linden::sdl2