#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include <utility>

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/joystick.hpp"
#include "enums/mouse_input.hpp"
#include "components/rigidbody.hpp"
#include "race/behaviours/ai_behaviour.hpp"

class Collider;

class MouseMovedEvent : public IEvent {
public:
    MouseMovedEvent(const int x, const int y) : IEvent(MouseMoved), x(x), y(y) {}

    int x, y;
};

class MousePressedEvent : public IEvent {
public:
    explicit MousePressedEvent(MouseInput btn) : IEvent(MousePressed), button(btn) {}

    MouseInput button;
};

class MouseReleasedEvent : public IEvent {
public:
    explicit MouseReleasedEvent(MouseInput btn) : IEvent(MouseReleased), button(btn) {}

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

class JoystickButtonPressedEvent : public IEvent {
public:
    explicit JoystickButtonPressedEvent(JoystickButton button) : IEvent(JoystickButtonPressed), button(button) {};
    JoystickButton button;
};

class JoystickButtonHoldEvent : public IEvent {
public:
    explicit JoystickButtonHoldEvent(JoystickButton button) : IEvent(JoystickButtonHold), button(button) {};
    JoystickButton button;
};

class JoystickButtonReleasedEvent : public IEvent {
public:
    explicit JoystickButtonReleasedEvent(JoystickButton button) : IEvent(JoystickButtonReleased), button(button) {};
    JoystickButton button;
};

class JoystickAxisChangedEvent : public IEvent {
public:
    JoystickAxisChangedEvent(JoystickAxis axis, float value) : IEvent(JoystickAxisChanged), axis(axis), value(value) {};
    JoystickAxis axis;
    float value;
};

class JoystickAxisCurrentEvent : public IEvent {
public:
    JoystickAxisCurrentEvent(JoystickAxis axis, float value) : IEvent(JoystickAxisCurrent), axis(axis), value(value) {};
    JoystickAxis axis;
    float value;
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

class AITargetReachedEvent : public IEvent {
public:
    AITargetReachedEvent(AIBehaviour &ai_behaviour, std::shared_ptr<GameObject> target) : IEvent(AITargetReached),
                                                                                          ai_behaviour(ai_behaviour),
                                                                                          target(std::move(target)) {};
    AIBehaviour &ai_behaviour;
    std::shared_ptr<GameObject> target;
};

#endif //ENGINE_EVENTS_HPP
