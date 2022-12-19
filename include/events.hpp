#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/mouse_input.hpp"
#include "components/rigidbody.hpp"

class UIObject;
class Collider;

class MouseMovedEvent : public IEvent {
public:
    MouseMovedEvent(const int x, const int y) : IEvent(MouseMoved), x(x), y(y) {}

    int x, y;
};

class MousePressedEvent : public IEvent {
public:
    explicit MousePressedEvent(MouseInput btn, const int x, const int y) : IEvent(MousePressed), button(btn), x(x), y(y) {}

    int x, y;
    MouseInput button;
};

class MouseReleasedEvent : public IEvent {
public:
    explicit MouseReleasedEvent(MouseInput btn, const int x, const int y) : IEvent(MouseReleased), button(btn), x(x), y(y) {}

    int x, y;
    MouseInput button;
};

class KeyPressedEvent : public IEvent {
public:
    explicit KeyPressedEvent(Key key) : IEvent(KeyPressed), key(key) {};
    Key key;
};

class KeyHoldEvent : public IEvent {
public:
    explicit KeyHoldEvent(Key key) : IEvent(KeyHold), key(key) {};
    Key key;
};

class KeyReleasedEvent : public IEvent {
public:
    explicit KeyReleasedEvent(Key key) : IEvent(KeyReleased), key(key) {};
    Key key;
};

class ColliderEntryEvent : public IEvent {
public:
    explicit ColliderEntryEvent(RigidBody *col_a, RigidBody *col_b) :
            IEvent(ColliderEntry), collider_a(col_a), collider_b(col_b) {};
    RigidBody *collider_a;
    RigidBody *collider_b;
};

class ColliderExitEvent : public IEvent {
public:
    explicit ColliderExitEvent(RigidBody *col_a, RigidBody *col_b) :
            IEvent(ColliderExit), collider_a(col_a), collider_b(col_b) {};
    RigidBody *collider_a;
    RigidBody *collider_b;
};

class SceneLoadedEvent : public IEvent {
public:
    SceneLoadedEvent() : IEvent(SceneLoaded) {}
};

class UiObjectPressedEvent : public IEvent {
public:
    UiObjectPressedEvent(MouseInput btn, UIObject& ui_object) : IEvent(UiObjectPressed), button(btn), ui_object(ui_object) {}

    MouseInput button;
    UIObject& ui_object;
};

class UiObjectReleasedEvent : public IEvent {
public:
    UiObjectReleasedEvent(MouseInput btn, UIObject& ui_object) : IEvent(UiObjectReleased), button(btn), ui_object(ui_object) {}

    MouseInput button;
    UIObject& ui_object;
};

#endif //ENGINE_EVENTS_HPP
