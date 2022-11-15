#pragma once

#include "components/component.hpp"
#include "gameobject.hpp"

class BehaviourScript : public Component {
public:
    /**
     * @brief Trigger happens only the first time
     */
    virtual void on_start();

    /**
     * @brief Continuous trigger
     */
    virtual void on_update();

//    /**
//     * @brief Sent when another object enters a trigger collider
//     *        attached to this object (2D physics only).
//     */
//    virtual void OnTriggerEnter2D(const Collider& collider);
//
//    /**
//     * @brief Sent when another object leaves a trigger collider
//     *        attached to this object (2D physics only).
//     */
//    virtual void OnTriggerExit2D(const Collider& collider);
//
//    /**
//     * @brief Sent each frame where another object is within a trigger
//     *        collider attached to this object (2D physics only).
//     */
//    virtual void OnTriggerStay2D(const Collider& collider);
};
