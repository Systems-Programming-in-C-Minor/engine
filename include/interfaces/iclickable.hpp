#ifndef ENGINE_ICLICKABLE_HPP
#define ENGINE_ICLICKABLE_HPP

class IClickable {
public:
    virtual void on_click() = 0;
    virtual ~IClickable() = default;
};

#endif //ENGINE_ICLICKABLE_HPP