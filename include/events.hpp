#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"

class Collider;

class MouseMovedEvent : public IEvent {
public:
    MouseMovedEvent(const int x, const int y) : IEvent(MouseMoved), x(x), y(y) {}
    int x, y;
};

class MousePressedEvent : public IEvent {
public:
    explicit MousePressedEvent(MouseInput btn): IEvent(MousePressed), button(btn) {}
    MouseInput button;
};

class MouseReleasedEvent : public IEvent {
public:
    explicit MouseReleasedEvent(MouseInput btn): IEvent(MouseReleased), button(btn) {}
    MouseInput button;
};

class KeyPressedEvent : public IEvent {
public:
    explicit KeyPressedEvent(Key key): IEvent(KeyPressed), key(key) {};
    Key key;
};

class KeyHoldEvent : public IEvent {
public:
    explicit KeyHoldEvent(Key key): IEvent(KeyHold), key(key) {};
    Key key;
};

class KeyReleasedEvent : public IEvent {
public:
    explicit KeyReleasedEvent(Key key): IEvent(KeyReleased), key(key) {};
    Key key;
};

class ColliderEntryEvent : public IEvent {
public:
    explicit ColliderEntryEvent(Collider& col): IEvent(ColliderEntry), collider(col) {};
    Collider& collider;
};

class ColliderExitEvent : public IEvent {
public:
    explicit ColliderExitEvent(Collider& col): IEvent(ColliderExit), collider(col) {};
    Collider& collider;
};

class SceneLoadedEvent : public IEvent {
public:
    SceneLoadedEvent() : IEvent(SceneLoaded) {}
};
#endif //ENGINE_EVENTS_HPP
