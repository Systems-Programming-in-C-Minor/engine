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
};
