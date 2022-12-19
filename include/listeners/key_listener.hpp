#ifndef ENGINE_IKEYLISTENER_HPP
#define ENGINE_IKEYLISTENER_HPP


#include "../include/managers/event_manager.hpp"
#include "events.hpp"

/**
 * @brief Interface for objects wanting to respond to keyboard events.
 */
class KeyListener {
protected:
    /**
     * @brief The explicit constructor.
     * @param event_manager The manager which registers listeners and notifies subscribers.
     */
    explicit KeyListener(EventManager &event_manager);

public:
    /**
     * @brief This method will be called whenever a key is pressed.
     *        Override for implementing the desired behaviour.
     * @param event The desired KeyPressedEvent.
     */
    virtual void on_key_pressed(const KeyPressedEvent &event) {};


    /**
     * @brief This method will be called whenever a pressed key is held.
     *        Override for implementing the desired behaviour.
     * @param event The desired KeyHoldEvent.
     */
    virtual void on_key_hold(const KeyHoldEvent &event) {};

    /**
     * @brief This method will be called whenever a pressed key is released again.
     *        Override for implementing the desired behaviour.
     * @param event The desired KeyReleasedEvent.
     */
    virtual void on_key_released(const KeyReleasedEvent &event) {};
};

#endif //ENGINE_IKEYLISTENER_HPP
