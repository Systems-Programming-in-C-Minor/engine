#pragma once

#include <functional>
#include "uiobject.hpp"

class Button : public UIObject {
public:
    Button(const std::string& name, const std::string& tag, double width, double height, bool interactable);
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
    void on_click(std::function<void()> callback) { _on_click = callback; }

    void set_interactable(bool is_interactable);

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
