#ifndef RACE_AI_TARGET_LISTENER_COMPONENT_HPP
#define RACE_AI_TARGET_LISTENER_COMPONENT_HPP

#include <vector>

#include "components/component.hpp"
#include "listeners/ai_listener.hpp"


/**
 * @brief Class which defines a listener for ai targets.
 */
class AITargetBehaviour : public Component, protected AIListener {
protected:
    std::vector<std::shared_ptr<GameObject>> _targets;
    int _target_index = 0;

    void on_target_reached(const AITargetReachedEvent &event) override;

public:
    /**
     * @brief Constructor.
     * @param event_manager The EventManager the behaviour will use to send/receive events.
     * @param target_vectors Targets for the AI to track.
     */
    AITargetBehaviour(EventManager &event_manager, const std::vector<Vector2d> &target_vectors);

    /**
     * @brief Returns the current target.
     */
    [[nodiscard]] std::shared_ptr<GameObject> get_target() const;

    /**
     * @brief Resets the target back to the initial one.
     */
    void reset();
};

#endif //RACE_AI_TARGET_LISTENER_COMPONENT_HPP