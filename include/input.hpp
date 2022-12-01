#ifndef ENGINE_INPUT_HPP
#define ENGINE_INPUT_HPP

#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "transform.hpp"

class SDL_Event;

class Input {
private:
    std::string parse_key(Key key);
    std::string parse_numeric_keys(Key key);
    std::string parse_alpha_keys(Key key);
    std::string parse_function_keys(Key key);

    std::string parse_mouseinput(MouseInput input);

public:
    Input() = default;
    ~Input();

    SDL_Event *_event;

    /**
     * @brief Is any key or mouse button currently held down?
     */
    bool any_key();

    /**
     * @brief Returns true the first frame the user hits any key or mouse button.
     */
    bool any_key_down();

    /**
     * @brief Returns the current mouse position in pixel coordinates
     */
    Vector2d mouse_position();

    /**
     * @brief Returns the value of the virtual axis identified by axisName.
     */
    double get_axis();

    /**
     * @brief Returns true while the user holds down the key identified by keycode.
     */
    bool get_key(Key key);

    /**
     * @brief Returns true during the frame the user starts pressing down the key identified by keycode.
     */
    bool get_key_down(Key key);

    /**
     * @brief Returns true during the frame the user releases the key identified by keycode.
     */
    bool get_key_up(Key key);

    /**
     * @brief Returns whether the given mouse button is held down.
     */
    bool get_mouse_button(MouseInput which);

    /**
     * @brief Returns true during the frame the user pressed the given mouse button.
     */
    bool get_mouse_button_down(MouseInput which);

    /**
     * @brief Returns true during the frame the user releases the given mouse button.
     */
    bool get_mouse_button_up(MouseInput which);
};

#endif //ENGINE_INPUT_HPP
