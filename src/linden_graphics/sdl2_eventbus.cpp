#include "sdl2_eventbus.h"

#include <algorithm>

namespace linden::graphics
{
    SDL2EventBus::SDL2EventBus()
    {
        on_key_up(
            [this](const SDL_Event& e)
            {
                _keys_down.erase(
                    std::remove(_keys_down.begin(), _keys_down.end(),
                                e.key.keysym.sym),
                    _keys_down.end());
            });
    }

    void SDL2EventBus::on_sdl_event(uint32_t sdl_event_type,
                                    SDL2EventCallback handler)
    {
        _sdl_event_handlers[sdl_event_type].push_back(handler);
    }

    void SDL2EventBus::on_window_close(SDL2EventCallback handler)
    {
        on_sdl_event(SDL_QUIT, handler);
    }

    void SDL2EventBus::on_key_down(SDL2EventCallback handler)
    {
        on_sdl_event(SDL_KEYDOWN, handler);
    }

    void SDL2EventBus::on_specific_key_down(SDL_Keycode key_code,
                                            SDL2EventCallback handler,
                                            bool only_first)
    {
        _sdl_key_down_handlers[key_code].push_back(
            std::make_pair(handler, only_first));
        if (!_specific_key_down_handler_registered)
        {
            on_key_down(
                [this](const SDL_Event& e)
                {
                    for (const auto& handler :
                         _sdl_key_down_handlers[e.key.keysym.sym])
                    {
                        const bool first_time =
                            std::find(_keys_down.begin(), _keys_down.end(),
                                      e.key.keysym.sym) == _keys_down.end();

                        if (first_time) _keys_down.push_back(e.key.keysym.sym);

                        if (handler.second && !first_time) continue;

                        handler.first(e);
                    }
                });
            _specific_key_down_handler_registered = true;
        }
    }

    void SDL2EventBus::on_key_up(SDL2EventCallback handler)
    {
        // Remove the keycode form the keys_down vector
        on_sdl_event(SDL_KEYUP, handler);
    }

    void SDL2EventBus::on_specific_key_up(SDL_Keycode key_code,
                                          SDL2EventCallback handler)
    {
        _sdl_key_up_handlers[key_code].push_back(handler);
        if (!_specific_key_up_handler_registered)
        {
            on_key_up(
                [this](const SDL_Event& e)
                {
                    for (const auto& handler :
                         _sdl_key_up_handlers[e.key.keysym.sym])
                    {
                        handler(e);
                    }
                });
            _specific_key_up_handler_registered = true;
        }
    }

    void SDL2EventBus::handle_sdl_events()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            for (const auto& handler : _sdl_event_handlers[event.type])
            {
                handler(event);
            }
        }
    }

    void SDL2EventBus::clear_handlers()
    {
        _sdl_event_handlers.clear();
    }
}  // namespace linden::graphics