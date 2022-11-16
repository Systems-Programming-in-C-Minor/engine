#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

class Component {
protected:
    Component() = default;
    bool active = true;
public:
    void set_active(bool is_active);
    [[nodiscard]] bool get_active() const;

    virtual ~Component() = default;
};

#endif //ENGINE_COMPONENT_HPP
