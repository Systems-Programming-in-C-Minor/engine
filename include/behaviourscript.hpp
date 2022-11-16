#include "components/component.hpp"
//#include "collider.hpp"

class BehaviourScript : public Component {
public:
    /**
     * @brief Function gets called on initialization
     */
    virtual void OnStart();

    /**
     * @brief Function gets called continuously
     */
    virtual void OnUpdate();

//        /**
//         * @brief Sent when another object enters a trigger collider
//         *        attached to this object (2D physics only).
//         * @spicapi
//         */
//        virtual void OnTriggerEnter2D(const Collider& collider);
//
//        /**
//         * @brief Sent when another object leaves a trigger collider
//         *        attached to this object (2D physics only).
//         * @spicapi
//         */
//        virtual void OnTriggerExit2D(const Collider& collider);
//
//        /**
//         * @brief Sent each frame where another object is within a trigger
//         *        collider attached to this object (2D physics only).
//         * @spicapi
//         */
//        virtual void OnTriggerStay2D(const Collider& collider);
};
