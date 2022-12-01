#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"

class Collider;

class MouseMovedEvent : public IEvent {
public:
    MouseMovedEvent() : IEvent("MouseMovedEvent") {}
};

class MouseClickedEvent : public IEvent {
public:
    explicit MouseClickedEvent(MouseInput btn): IEvent("MouseClickedEvent"), button(btn) {}
    MouseInput button;
};

class MouseButtonEvent : public IEvent {
public:
    explicit MouseButtonEvent(MouseInput btn): IEvent("MouseButtonEvent"), button(btn) {}
    MouseInput button;
};

class MousePressedEvent : public IEvent {
public:
    explicit MousePressedEvent(MouseInput btn): IEvent("MousePressedEvent"), button(btn) {}
    MouseInput button;
};

class MouseReleasedEvent : public IEvent {
public:
    explicit MouseReleasedEvent(MouseInput btn): IEvent("MouseReleasedEvent"), button(btn) {}
    MouseInput button;
};

class KeyPressedEvent : public IEvent {
public:
    explicit KeyPressedEvent(Key key): IEvent("KeyPressedEvent"), key(key) {};
    Key key;
};

class KeyReleasedEvent : public IEvent {
public:
    explicit KeyReleasedEvent(Key key): IEvent("KeyReleasedEvent"), key(key) {};
    Key key;
};

class ColliderExitEvent : public IEvent {
public:
    explicit ColliderExitEvent(Collider& col): IEvent("ColliderExitEvent"), collider(col) {};
    Collider& collider;
};

class ColliderEntryEvent : public IEvent {
public:
    explicit ColliderEntryEvent(Collider& col): IEvent("ColliderEntryEvent"), collider(col) {};
    Collider& collider;
};

class ColliderStayEvent : public IEvent {
public:
    explicit ColliderStayEvent(Collider& col): IEvent("ColliderStayEvent"), collider(col) {};
    Collider& collider;
};

class SceneLoadedEvent : public IEvent {
public:
    SceneLoadedEvent() : IEvent("SceneLoadedEvent") {}
};
#endif //ENGINE_EVENTS_HPP
