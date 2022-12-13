#ifndef ENGINE_IEVENT_HPP
#define ENGINE_IEVENT_HPP

#include <utility>

enum Event {
    MouseMoved,
    MousePressed,
    MouseReleased,
    KeyPressed,
    KeyHold,
    KeyReleased,
    ColliderEntry,
    ColliderExit,
    SceneLoaded,
};

class IEvent {
protected:
    explicit IEvent(Event event) : event(event) {}

public:
    const Event event;

    virtual ~IEvent() = default;
};

#endif //ENGINE_IEVENT_HPP
