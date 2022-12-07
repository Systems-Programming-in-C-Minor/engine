#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"

class Collider;

class MouseMovedEvent : public IEvent {
public:
    MouseMovedEvent(const int x, const int y) : IEvent(MouseMoved), x(x), y(y) {}
    int x;
    int y;
};

class MouseClickedEvent : public IEvent {
public:
    explicit MouseClickedEvent(MouseInput btn): IEvent(MouseClicked), button(btn) {}
    MouseInput button;
};

class MouseButtonEvent : public IEvent {
public:
    explicit MouseButtonEvent(MouseInput btn): IEvent(MouseButton), button(btn) {}
    MouseInput button;
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

class KeyReleasedEvent : public IEvent {
public:
    explicit KeyReleasedEvent(Key key): IEvent(KeyReleased), key(key) {};
    Key key;
};

class ColliderExitEvent : public IEvent {
public:
    explicit ColliderExitEvent(Collider& col): IEvent(ColliderExit), collider(col) {};
    Collider& collider;
};

class ColliderEntryEvent : public IEvent {
public:
    explicit ColliderEntryEvent(Collider& col): IEvent(ColliderEntry), collider(col) {};
    Collider& collider;
};

class ColliderStayEvent : public IEvent {
public:
    explicit ColliderStayEvent(Collider& col): IEvent(ColliderStay), collider(col) {};
    Collider& collider;
};

class SceneLoadedEvent : public IEvent {
public:
    SceneLoadedEvent() : IEvent(SceneLoaded) {}
};
#endif //ENGINE_EVENTS_HPP
