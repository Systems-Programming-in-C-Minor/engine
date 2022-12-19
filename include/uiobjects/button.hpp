#pragma once

#include <functional>
#include "uiobject.hpp"

/**
 * @brief Instances of this class are clickable user interface items.
 */
class Button : public UIObject {
public:
    /**
     * @brief Constructor.
     * @param name The name of the button GameObject.
     * @param tag The tag of the button GameObject.
     * @param is_world_space Boolean option if the button will be rendered in world space.
     * @param transform The transform of the button.
     * @param width The width of the button.
     * @param height The height of the button.
     * @param interactable Boolean option if the button is interactable.
     */
    Button(const std::string& name, const std::string& tag, bool is_world_space, Transform transform, int width, int height, bool interactable);

    /**
     * @brief This function is called when the button is clicked, which
     *        will trigger a call to the registered onClick member.
     */
    void click();

    /**
     * @brief Register the onClick handler to be used when the button is clicked.
     * @param callback The function to register, usually a lambda. But this can be
     *        any kind of callable.
     */
    void on_click(std::function<void()> callback);

    /**
     * @brief Setter for the interactable variable.
     * @param is_interactable Set the interactable boolean to this value.
     */
    void set_interactable(bool is_interactable);

    /**
     * @brief Getter for the interactable variable.
     * @return The interactable boolean value.
     */
    [[nodiscard]] bool get_interactable() const;

private:
    /**
     * @brief When false, the button will not react to clicks.
     */
    bool _interactable;

    /**
     * @brief The registered click handler.
     */
    std::function<void()> _on_click;
};
