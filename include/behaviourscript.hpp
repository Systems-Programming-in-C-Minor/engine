#include "components/component.hpp"
//#include "collider.hpp"

class BehaviourScript : public Component {
public:
    /**
     * @brief Function gets called on initialization
     */
    virtual void on_start();

    /**
     * @brief Function gets called continuously
     */
    virtual void on_update();

//    /**
//     * @brief Sent when another object enters a trigger collider
//     *        attached to this object (2D physics only).
//     */
//    virtual void on_trigger_enter_2D(const Collider& collider);
//
//    /**
//     * @brief Sent when another object leaves a trigger collider
//     *        attached to this object (2D physics only).
//     */
//    virtual void on_trigger_exit_2D(const Collider& collider);
//
//    /**
//     * @brief Sent each frame where another object is within a trigger
//     *        collider attached to this object (2D physics only).
//     */
//    virtual void on_trigger_stay_2D(const Collider& collider);
};
