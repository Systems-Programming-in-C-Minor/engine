#ifndef ENGINE_IEVENT_HPP
#define ENGINE_IEVENT_HPP

#include <utility>

class IEvent {
protected:
    explicit IEvent(std::string name) : name(std::move(name)) {}

public:
    const std::string name;

    virtual ~IEvent() = default;
};

#endif //ENGINE_IEVENT_HPP
