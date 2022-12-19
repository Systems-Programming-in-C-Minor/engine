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
    Component(const std::string name = "");
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
    [[nodiscard]] std::string get_name() const;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Component() = default;
};

#endif //ENGINE_COMPONENT_HPP