#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

class GameObject;

class Component {
protected:
    Component() = default;
    bool active = true;
    friend class GameObject;
public:
    GameObject* game_object = nullptr;
    virtual void set_active(bool is_active);
    [[nodiscard]] bool get_active() const;

    virtual ~Component() = default;
};

#endif //ENGINE_COMPONENT_HPP