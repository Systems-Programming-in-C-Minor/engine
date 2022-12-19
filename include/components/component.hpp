#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP
#include <string>

class GameObject;

class Component {
private:
    const std::string _name;
protected:
    Component(const std::string name = "");
    bool active = true;
    friend class GameObject;
public:
    GameObject* game_object = nullptr;
    virtual void set_active(bool is_active);
    [[nodiscard]] bool get_active() const;
    [[nodiscard]] std::string get_name() const;

    virtual ~Component() = default;
};

#endif //ENGINE_COMPONENT_HPP