#ifndef ENGINE_INPUT_HPP
#define ENGINE_INPUT_HPP

#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"
#include <vector>

/**
 * @brief Some convenient input functions.
 */
class Input {

public:
    /**
    * @brief A vector containing previously pressed keys (Key).
    */
    std::vector<Key> _previous_keystate;

    /**
    * @brief A vector containing previous MouseInput.
     * */
    std::vector<MouseInput> _previous_mousestate;

    /**
     * @brief Default constructor.
     */
    Input() = default;

    /**
     * @brief Return all keys that have been pressed.
     * @return A vector containing the keys which have been pressed.
     */
    std::vector<Key> fetch_keystate();

    /**
     * @brief Return all mouse buttons that have been pressed.
     * @return A vector containing the mouse buttons which have been pressed.
     */
    std::vector<MouseInput> fetch_mousestate();

    /**
     * @brief Is any key or mouse button currently held down?
     * @return Boolean value whether or not this is true.
     */
    bool any_key();

    /**
     * @brief Returns true the first frame the user hits any key or mouse button.
     * @return Boolean value whether or not this is true.
     */
    bool any_key_down();

    /**
     * @brief Returns the current mouse position in pixel coordinates
     * @return A Vector2d containing the current mouse position.
     */
    Vector2d mouse_position();

    /**
     * @brief Returns true while the user holds down the key identified by keycode.
     * @param key The key which is being checked.
     * @return Boolean value whether or not this is true.
     */
    bool get_key(Key key);

    /**
     * @brief Returns true during the frame the user starts pressing down the key identified by keycode.
     * @param key The key which is being checked.
     * @return Boolean value whether or not this is true.
     */
    bool get_key_down(Key key);

    /**
     * @brief Returns true during the frame the user releases the key identified by keycode.
     * @param key The key which is being checked.
     * @return Boolean value whether or not this is true.
     */
    bool get_key_up(Key key);

    /**
     * @brief Returns whether the given mouse button is held down.
     * @param which The MouseInput which is being checked.
     * @return Boolean value whether or not this is true.
     */
    bool get_mouse_button(MouseInput which);

    /**
     * @brief Returns true during the frame the user pressed the given mouse button.
     * @param which The MouseInput which is being checked.
     * @return Boolean value whether or not this is true.
     */
    bool get_mouse_button_down(MouseInput which);

    /**
     * @brief Returns true during the frame the user releases the given mouse button.
     * @param which The MouseInput which is being checked.
     * @return Boolean value whether or not this is true.
     */
    bool get_mouse_button_up(MouseInput which);

    /**
     * @brief Returns the controller count as an integer value.
     * @return Static int value of the count of current controllers.
     */
    [[nodiscard]] static int get_controller_count();
};

#endif //ENGINE_INPUT_HPP
