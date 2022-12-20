
#ifndef ENGINE_KEY_HANDLER_HPP
#define ENGINE_KEY_HANDLER_HPP

#include <vector>
#include <list>
#include <map>
#include "../include/enums/key.hpp"
#include "enums/joystick.hpp"

class _SDL_Joystick;

/**
 * @brief A handler for keyboard input.
 */
class KeyHandler {

private:
    std::vector<Key> _keys_active;
    std::vector<_SDL_Joystick *> _joysticks;
    std::map<int, std::list<JoystickButton>> _joystick_buttons_active;
    std::map<int, std::map<JoystickAxis, float>> _joystick_axes_values;

    /**
     * @brief Method which fetches the keyboard input.
     * @return A vector containing all registered keyboard input.
     * */
    static std::vector<Key> fetch_keys();

    /**
     * Method which notifies an event manager when a button is pressed, held or released.
     * @param joystick The joystick currently in use.
     * @param button The button which has been pressed.
     * @param value The value of the button pressed.
     */
    void _fire_joystick_button_event_if_changed(_SDL_Joystick *joystick, JoystickButton button, int value);

    /**
     * Method which notifies an event manager when the axis of the controller changes.
     * @param joystick The joystick currently in use.
     * @param axis The axis which has changed.
     * @param value The value of the button pressed.
     */
    void _fire_joystick_axis_event_if_changed(_SDL_Joystick *joystick, JoystickAxis axis, int value);

    /**
     * Normalize the axis of the controller.
     * @param value The integer value used for normalizing the axis.
     * @returns The normalized value as a float.
     */
    static float _normalize_axis(int value);

public:
    /**
     * @brief Method which gets called every tick.
     * */
    void tick();

    /**
     * @brief Return the number of registered controllers.
     * @return The current amount of controllers as an unsigned long.
     */
    [[nodiscard]] unsigned long get_number_of_controllers() const;

    /**
     * @brief The constructor.
     * */
    KeyHandler();

    /**
     * @brief The destructor.
     * */
    ~KeyHandler();
};

#endif //ENGINE_KEY_HANDLER_HPP
