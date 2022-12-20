#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

class GameObject;

/**
 * @brief Base class for all components.
 */
class Component {
protected:
    /**
     * @brief Default Constructor.
     */
    Component() = default;

    bool active = true;
    friend class GameObject;
public:
    GameObject* game_object = nullptr;

    /**
     * @brief Set new is_active status.
     * @param is_active The new is_active status.
     */
    virtual void set_active(bool is_active);

    /**
     * @brief Getter for active status.
     * @return true if active, false otherwise.
     */
    [[nodiscard]] bool get_active() const;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Component() = default;
};

#endif //ENGINE_COMPONENT_HPP