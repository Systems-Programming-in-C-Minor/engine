#ifndef ENGINE_IEVENT_HPP
#define ENGINE_IEVENT_HPP

#include <utility>

/**
 * @brief Enumeration for different event types.
 */
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
    JoystickButtonPressed,
    JoystickButtonHold,
    JoystickButtonReleased,
    JoystickAxisCurrent,
    JoystickAxisChanged,
    AITargetReached,
    CheckpointTouched,
    CheckpointReached,
    CheckpointLapped,
    UiObjectPressed,
    UiObjectReleased,
    UserJoinedMultiplayer,
    UserLeftMultiplayer,
    AllocationMultiplayer,
    UsersMultiplayer,
    HostMultiplayer,
    StartGameMultiplayer,
    StopGameMultiplayer,
};

/**
 * @brief Interface for all Event types.
 */
class IEvent {
protected:
    /**
     * @brief Explicit constructor.
     * @param event The desired event type.
     */
    explicit IEvent(Event event) : event(event) {}

public:
    /**
     * @brief The actual Event object.
     */
    const Event event;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IEvent() = default;
};

#endif //ENGINE_IEVENT_HPP
