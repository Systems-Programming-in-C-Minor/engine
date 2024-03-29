#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP
#include <string>

class GameObject;

/**
 * @brief Base class for all components.
 */
class Component {
private:
    const std::string _name;
protected:
    /**
     * @brief Constructor.
     * @param name Set the name of the Component.
     */
    explicit Component(std::string name = "");

    bool active = true;

    virtual void on_parent_set();

    friend class GameObject;
public:
    /**
     * @brief The GameObject of the Component.
     */
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
    [[nodiscard]] std::string get_name() const;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Component() = default;
};

#endif //ENGINE_COMPONENT_HPP