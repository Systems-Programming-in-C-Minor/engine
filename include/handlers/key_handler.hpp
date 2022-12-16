
#ifndef ENGINE_KEY_HANDLER_HPP
#define ENGINE_KEY_HANDLER_HPP

#include <vector>
#include <list>
#include <map>
#include "../include/enums/key.hpp"
#include "enums/joystick.hpp"

class _SDL_Joystick;

class KeyHandler {

private:
    std::vector<Key> _keys_active;
    std::vector<_SDL_Joystick *> _joysticks;
    std::map<int, std::list<JoystickButton>> _joystick_buttons_active;
    std::map<int, std::map<JoystickAxis, float>> _joystick_axes_values;

    static std::vector<Key> fetch_keys();

    void _fire_joystick_button_event_if_changed(_SDL_Joystick *joystick, JoystickButton button, int value);
    void _fire_joystick_axis_event_if_changed(_SDL_Joystick *joystick, JoystickAxis axis, int value);
    static float _normalize_axis(int value);

public:
    void tick();

    KeyHandler();

    ~KeyHandler();
};

#endif //ENGINE_KEY_HANDLER_HPP
