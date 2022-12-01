#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"

class Collider;

class MouseMovedEvent : IEvent {};

class MouseClickedEvent : IEvent {
public:
    MouseClickedEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class MouseButtonEvent : IEvent {
public:
    MouseButtonEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class MousePressedEvent : IEvent {
public:
    MousePressedEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class MouseReleasedEvent : IEvent {
public:
    MouseReleasedEvent(MouseInput btn): button(btn) {}
    MouseInput button;
};

class KeyPressedEvent : IEvent {
public:
    KeyPressedEvent(Key key): key(key) {};
    Key key;
};

class KeyReleasedEvent : IEvent {
public:
    KeyReleasedEvent(Key key): key(key) {};
    Key key;
};

class ColliderExitEvent : IEvent {
public:
    ColliderExitEvent(Collider& col): collider(col) {};
    Collider& collider;
};

class ColliderEntryEvent : IEvent {
public:
    ColliderEntryEvent(Collider& col): collider(col) {};
    Collider& collider;
};

class ColliderStayEvent : IEvent {
public:
    ColliderStayEvent(Collider& col): collider(col) {};
    Collider& collider;
};

class SceneLoadedEvent : IEvent {};
#endif //ENGINE_EVENTS_HPP
