#include "race/components/ai_target_listener_component.hpp"

#include "transform.hpp"
#include "gameobject.hpp"

AITargetListenerComponent::AITargetListenerComponent(EventManager &event_manager, const std::vector <Vector2d>& target_vectors)  : AIListener(event_manager) {
    for (int i = 0; i < target_vectors.size(); ++i) {
        _targets.push_back(std::make_shared<GameObject>("Target " + std::to_string(i), "target", Transform{target_vectors[i]}));
    }
}

void AITargetListenerComponent::on_target_reached(const AITargetReachedEvent &event) {
    auto ai_behaviour = game_object->get_component<AIBehaviour>();

    if (ai_behaviour == nullptr)
        return;

    if (event.ai_behaviour.game_object != ai_behaviour->game_object)
        return;

    _target_index++;
    if (_targets.size() <= _target_index) {
        _target_index = 0;
    }
    event.ai_behaviour.set_target(_targets[_target_index]);
}

std::shared_ptr<GameObject> AITargetListenerComponent::get_target() const {
    return _targets[_target_index];
}

void AITargetListenerComponent::reset() {
    auto ai_behaviour = game_object->get_component<AIBehaviour>();

    _target_index = 0;

    if (ai_behaviour != nullptr)
        ai_behaviour->set_target(_targets[_target_index]);
}
