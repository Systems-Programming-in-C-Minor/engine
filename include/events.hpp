#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"

class Collider;

class MouseMovedEvent : public IEvent {};

class MouseClickedEvent : public IEvent {
public:
    explicit MouseClickedEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class MouseButtonEvent : public IEvent {
public:
    explicit MouseButtonEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class MousePressedEvent : public IEvent {
public:
    explicit MousePressedEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class MouseReleasedEvent : public IEvent {
public:
    explicit MouseReleasedEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class KeyPressedEvent : public IEvent {
public:
    explicit KeyPressedEvent(Key key): key(key) {};
    Key key;
};

class KeyReleasedEvent : public IEvent {
public:
    explicit KeyReleasedEvent(Key key): key(key) {};
    Key key;
};

class ColliderExitEvent : public IEvent {
public:
    explicit ColliderExitEvent(Collider& col): collider(col) {};
    Collider& collider;
};

class ColliderEntryEvent : public IEvent {
public:
    explicit ColliderEntryEvent(Collider& col): collider(col) {};
    Collider& collider;
};

class ColliderStayEvent : public IEvent {
public:
    explicit ColliderStayEvent(Collider& col): collider(col) {};
    Collider& collider;
};

class SceneLoadedEvent : public IEvent {};
#endif //ENGINE_EVENTS_HPP
