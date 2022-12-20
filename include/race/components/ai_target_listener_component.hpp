#ifndef RACE_AI_TARGET_LISTENER_COMPONENT_HPP
#define RACE_AI_TARGET_LISTENER_COMPONENT_HPP

#include <vector>

#include "components/component.hpp"
#include "listeners/ai_listener.hpp"

class AITargetListenerComponent : public Component, protected AIListener {
protected:
    std::vector<std::shared_ptr<GameObject>> _targets;
    int _target_index = 0;

    void on_target_reached(const AITargetReachedEvent &event) override;

public:
    AITargetListenerComponent(EventManager &event_manager, const std::vector<Vector2d> &target_vectors);

    [[nodiscard]] std::shared_ptr<GameObject> get_target() const;

    void reset();
};

#endif //RACE_AI_TARGET_LISTENER_COMPONENT_HPP