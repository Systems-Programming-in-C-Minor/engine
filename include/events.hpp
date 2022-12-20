#ifndef ENGINE_EVENTS_HPP
#define ENGINE_EVENTS_HPP

#include <utility>
#include <list>

#include "interfaces/ievent.hpp"
#include "enums/key.hpp"
#include "enums/joystick.hpp"
#include "enums/mouse_input.hpp"
#include "components/rigidbody.hpp"
#include "race/behaviours/ai_behaviour.hpp"

class UIObject;
class Collider;
class CheckpointBehaviour;
class Checkpoint;

/**
 * @brief Class for handling MouseMovedEvents.
 */
class MouseMovedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param y The x position of the current position of the mouse.
     * @param y The y position of the current position of the mouse.
     */
    MouseMovedEvent(const int x, const int y) : IEvent(MouseMoved), x(x), y(y) {}

    int x, y;
};

/**
 * @brief Class for handling MousePressedEvents.
 */
class MousePressedEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param btn The mouse button that has been pressed.
     * @param y The x position of the current position of the mouse.
     * @param y The y position of the current position of the mouse.
     */
    explicit MousePressedEvent(MouseInput btn, const int x, const int y) : IEvent(MousePressed), button(btn), x(x), y(y) {}

    int x, y;
    MouseInput button;
};

/**
 * @brief Class for handling MouseReleasedEvents.
 */
class MouseReleasedEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param btn The mouse button that has been released.
     * @param y The x position of the current position of the mouse.
     * @param y The y position of the current position of the mouse.
     */
    explicit MouseReleasedEvent(MouseInput btn, const int x, const int y) : IEvent(MouseReleased), button(btn), x(x), y(y) {}

    int x, y;
    MouseInput button;
};

/**
 * @brief Class for handling KeyPressedEvents.
 */
class KeyPressedEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param key The key that has been pressed.
     */
    explicit KeyPressedEvent(Key key) : IEvent(KeyPressed), key(key) {};
    Key key;
};

/**
 * @brief Class for handling KeyHoldEvents.
 */
class KeyHoldEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param key The key that is being held.
     */
    explicit KeyHoldEvent(Key key) : IEvent(KeyHold), key(key) {};
    Key key;
};

/**
 * @brief Class for handling KeyReleasedEvents.
 */
class KeyReleasedEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param key The key that has been released.
     */
    explicit KeyReleasedEvent(Key key) : IEvent(KeyReleased), key(key) {};
    Key key;
};

/**
 * @brief Class for handling JoystickButtonPressedEvents.
 */
class JoystickButtonPressedEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param joystick_id The id of the joystick.
     * @param button The joystick button that has been pressed.
     */
    explicit JoystickButtonPressedEvent(int joystick_id, JoystickButton button) : IEvent(JoystickButtonPressed),
                                                                                  joystick_id(joystick_id),
                                                                                  button(button) {};
    int joystick_id;
    JoystickButton button;
};

/**
 * @brief Class for handling JoystickButtonHoldEvents.
 */
class JoystickButtonHoldEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param joystick_id The id of the joystick.
     * @param button The joystick button that is being held.
     */
    explicit JoystickButtonHoldEvent(int joystick_id, JoystickButton button) : IEvent(JoystickButtonHold),
                                                                               joystick_id(joystick_id),
                                                                               button(button) {};
    int joystick_id;
    JoystickButton button;
};

/**
 * @brief Class for handling JoystickButtonReleasedEvents.
 */
class JoystickButtonReleasedEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param joystick_id The id of the joystick.
     * @param button The joystick button that has been released.
     */
    explicit JoystickButtonReleasedEvent(int joystick_id, JoystickButton button) : IEvent(JoystickButtonReleased),
                                                                                   joystick_id(joystick_id),
                                                                                   button(button) {};
    int joystick_id;
    JoystickButton button;
};

/**
 * @brief Class for handling JoystickAxisChangedEvents.
 */
class JoystickAxisChangedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param joystick_id The id of the joystick.
     * @param axis The axis that has been changed.
     * @param value The value by which the axis has changed.
     */
    JoystickAxisChangedEvent(int joystick_id, JoystickAxis axis, float value) : IEvent(JoystickAxisChanged),
                                                                                joystick_id(joystick_id), axis(axis),
                                                                                value(value) {};
    int joystick_id;
    JoystickAxis axis;
    float value;
};

/**
 * @brief Class for handling JoystickAxisCurrentEvents.
 */
class JoystickAxisCurrentEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param joystick_id The id of the joystick.
     * @param axis The current joystick axis.
     * @param value The value of the current joystick axis.
     */
    JoystickAxisCurrentEvent(int joystick_id, JoystickAxis axis, float value) : IEvent(JoystickAxisCurrent),
                                                                                joystick_id(joystick_id), axis(axis),
                                                                                value(value) {};
    int joystick_id;
    JoystickAxis axis;
    float value;
};

/**
 * @brief Class for handling ColliderEntryEvents.
 */
class ColliderEntryEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param col_a The collider that is touching collider b.
     * @param col_b The collider that is touching collider a.
     * @param is_touching Boolean value whether or not the colliders are touching.
     */
    explicit ColliderEntryEvent(RigidBody *col_a, RigidBody *col_b, bool is_touching) :
            IEvent(ColliderEntry), collider_a(col_a), collider_b(col_b), is_touching(is_touching) {};
    RigidBody *collider_a;
    RigidBody *collider_b;
    const bool is_touching;
};

/**
 * @brief Class for handling ColliderExitEvents.
 */
class ColliderExitEvent : public IEvent {
public:
    /**
     * @brief Explicit constructor.
     * @param col_a The collider that is leaving collider b.
     * @param col_b The collider that is leaving collider a.
     * @param is_touching Boolean value whether or not the colliders are touching.
     */
    explicit ColliderExitEvent(RigidBody *col_a, RigidBody *col_b, bool is_touching) :
            IEvent(ColliderExit), collider_a(col_a), collider_b(col_b), is_touching(is_touching) {};
    RigidBody *collider_a;
    RigidBody *collider_b;
    const bool is_touching;
};

/**
 * @brief Class for handling SceneLoadedEvents.
 */
class SceneLoadedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     */
    SceneLoadedEvent() : IEvent(SceneLoaded) {}
};

/**
 * @brief Class for handling AITargetReachedEvents.
 */
class AITargetReachedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param ai_behaviour The ai behaviour of the object.
     * @param target The target that has been reached.
     */
    AITargetReachedEvent(AIBehaviour &ai_behaviour, std::shared_ptr<GameObject> target) : IEvent(AITargetReached),
                                                                                          ai_behaviour(ai_behaviour),
                                                                                          target(std::move(target)) {};
    AIBehaviour &ai_behaviour;
    std::shared_ptr<GameObject> target;
};

/**
 * @brief Class for handling CheckpointTouchedEvents.
 */
class CheckpointTouchedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param checkpoint_behaviour The ai behaviour of the object.
     * @param checkpoint The checkpoint that has been touched.
     */
    CheckpointTouchedEvent(CheckpointBehaviour *checkpoint_behaviour, std::shared_ptr<Checkpoint> checkpoint) :
            IEvent(CheckpointTouched), checkpoint_behaviour(checkpoint_behaviour), checkpoint(std::move(checkpoint)) {}

    CheckpointBehaviour *checkpoint_behaviour;
    std::shared_ptr<Checkpoint> checkpoint;
};

/**
 * @brief Class for handling CheckpointReachedEvents.
 */
class CheckpointReachedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param checkpoint_behaviour The ai behaviour of the object.
     * @param checkpoint The checkpoint that has been reached.
     */
    CheckpointReachedEvent(CheckpointBehaviour *checkpoint_behaviour, std::shared_ptr<Checkpoint> checkpoint) :
            IEvent(CheckpointReached), checkpoint_behaviour(checkpoint_behaviour), checkpoint(std::move(checkpoint)) {}

    CheckpointBehaviour *checkpoint_behaviour;
    std::shared_ptr<Checkpoint> checkpoint;
};

/**
 * @brief Class for handling CheckpointLappedEvents.
 */
class CheckpointLappedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param checkpoint_behaviour The ai behaviour of the object.
     * @param checkpoint The checkpoint that has been lapped.
     */
    CheckpointLappedEvent(CheckpointBehaviour *checkpoint_behaviour, std::shared_ptr<Checkpoint> checkpoint) :
        IEvent(CheckpointLapped), checkpoint_behaviour(checkpoint_behaviour), checkpoint(std::move(checkpoint)) {}

    CheckpointBehaviour *checkpoint_behaviour;
    std::shared_ptr<Checkpoint> checkpoint;
};

/**
 * @brief Class for handling UiObjectPressedEvents.
 */
class UiObjectPressedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param btn The mouse button that has been pressed.
     * @param ui_object The ui object which has been pressed.
     */
    UiObjectPressedEvent(MouseInput btn, UIObject& ui_object) : IEvent(UiObjectPressed), button(btn), ui_object(ui_object) {}

    MouseInput button;
    UIObject& ui_object;
};

/**
 * @brief Class for handling UiObjectReleasedEvents.
 */
class UiObjectReleasedEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param btn The mouse button that has been released.
     * @param ui_object The ui object which has been released.
     */
    UiObjectReleasedEvent(MouseInput btn, UIObject& ui_object) : IEvent(UiObjectReleased), button(btn), ui_object(ui_object) {}

    MouseInput button;
    UIObject& ui_object;
};

/**
 * @brief Class for handling UserJoinedMultiplayerEvents.
 */
class UserJoinedMultiplayerEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param user_id The user id of the user that joined the session.
     */
    UserJoinedMultiplayerEvent(const int user_id) : IEvent(UserJoinedMultiplayer), user_id(user_id) {}

    int user_id;
};

/**
 * @brief Class for handling UserLeftMultiplayerEvents.
 */
class UserLeftMultiplayerEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param user_id The user id of the user that left the session.
     */
    UserLeftMultiplayerEvent(const int user_id) : IEvent(UserLeftMultiplayer), user_id(user_id) {}

    int user_id;
};

/**
 * @brief Class for handling AllocationMultiplayerEvents.
 */
class AllocationMultiplayerEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param user_id The user id you have received upon joining the session.
     */
    AllocationMultiplayerEvent(const int user_id) : IEvent(AllocationMultiplayer), user_id(user_id) {}

    int user_id;
};

/**
 * @brief Class for handling UsersMultiplayerEvents.
 */
class UsersMultiplayerEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     * @param user_ids The ids of the users currently in the multiplayer session.
     */
    UsersMultiplayerEvent(std::list<int> user_ids) : IEvent(UsersMultiplayer), user_ids(std::move(user_ids)) {}

    std::list<int> user_ids;
};

/**
 * @brief Class for handling HostMultiplayerEvents.
 */
class HostMultiplayerEvent : public IEvent {
public:
    /**
     * @brief Constructor.
     */
    HostMultiplayerEvent() : IEvent(HostMultiplayer) {}
};

#endif //ENGINE_EVENTS_HPP
