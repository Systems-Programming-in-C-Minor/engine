#pragma once

#include "UIObject.hpp"
#include <functional>

/**
 * @brief Instances of this class are clickable user interface items.
 */
class Button : public UIObject {
public:
    Button(bool interactable);
    /**
     * @brief This function is called when the button is clicked, which
     *        will trigger a call to the registered onClick member.
     * @spicapi
     */
    void Click();

    /**
     * @brief Register the onClick handler to be used when the button is clicked.
     * @param callback The function to register, usually a lambda. But this can be
     *        any kind of callable.
     * @spicapi
     */
    void OnClick(std::function<void()> callback) { onClick = callback; }

    void setInteractable(bool newInteractable) { interactable = newInteractable; }

private:
    /**
     * @brief When false, the button will not react to clicks.
     */
    bool interactable;

    /**
     * @brief The registered click handler.
     */
    std::function<void()> onClick;
};
