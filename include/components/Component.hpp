#pragma once

class Component {
protected:
    Component() = default;
    bool active = true;
public:
    void setActive(bool isActive);
    [[nodiscard]] bool getActive() const;

    virtual ~Component() = default;
};