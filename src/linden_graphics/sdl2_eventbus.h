#pragma once

#include <SDL2/SDL.h>

#include <chrono>
#include <functional>
#include <map>
#include <string>
#include <vector>

namespace linden::graphics
{
    using SDL2EventCallback = std::function<void(const SDL_Event&)>;

    class SDL2EventBus
    {
    private:
        std::map<uint32_t, std::vector<SDL2EventCallback>> _sdl_event_handlers;
        std::map<SDL_Keycode, std::vector<std::pair<SDL2EventCallback, bool>>>
            _sdl_key_down_handlers;
        std::map<SDL_Keycode, std::vector<SDL2EventCallback>>
            _sdl_key_up_handlers;
        bool _specific_key_down_handler_registered = false;
        bool _specific_key_up_handler_registered = false;
        std::vector<SDL_Keycode> _keys_down;

    public:
        SDL2EventBus();

        // SDL event handlers
        void on_sdl_event(uint32_t sdl_event_type, SDL2EventCallback handler);

        void on_window_close(SDL2EventCallback handler);

        // Keyboard handlers
        void on_key_down(SDL2EventCallback handler);
        void on_specific_key_down(SDL_Keycode key_code,
                                  SDL2EventCallback handler,
                                  bool only_first = false);
        void on_key_up(SDL2EventCallback handler);
        void on_specific_key_up(SDL_Keycode key_code,
                                SDL2EventCallback handler);

        // Handle all events
        void handle_sdl_events();

        // Clear handlers
        void clear_handlers();
    };
}  // namespace linden::graphics