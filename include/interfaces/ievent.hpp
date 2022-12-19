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
};

/**
 * @brief Interface for all Event types.
 */
class IEvent {
    /**
     * @brief Explicit constructor.
     * @param event The desired event type.
     */
protected:
    explicit IEvent(Event event) : event(event) {}

public:
    const Event event;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IEvent() = default;
};

#endif //ENGINE_IEVENT_HPP
