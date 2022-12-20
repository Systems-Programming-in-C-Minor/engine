#include "race/behaviours/multiplayer_behaviour.hpp"

#include <utility>
#include "race/objects/car.hpp"
#include "race/components/ai_target_listener_component.hpp"
#include "global.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/behaviours/drive_input_controller_behaviour.hpp"


MultiplayerBehaviour::MultiplayerBehaviour(EventManager &event_manager,
                                           std::shared_ptr<NetworkableCar> networkable_car,
                                           int car_id,
                                           std::vector<Vector2d> targets) :
        MultiplayerListener(event_manager),
        _networkable_car(std::move(networkable_car)),
        _car_id(car_id),
        _event_manager(event_manager),
        _targets(std::move(targets)) {}

void MultiplayerBehaviour::on_user_join(const UserJoinedMultiplayerEvent &event) {
    if (event.user_id != _car_id) return;
    if (!Global::get_instance()->get_engine().multiplayer_manager->is_host) return;

    _networkable_car->car->remove_component<AIBehaviour>();
    _networkable_car->car->get_component<AITargetListenerComponent>()->reset();

    _networkable_car->transmit = false;
    _networkable_car->receive = true;
}

void MultiplayerBehaviour::on_user_leave(const UserLeftMultiplayerEvent &event) {
    if (event.user_id != _car_id) return;
    if (!Global::get_instance()->get_engine().multiplayer_manager->is_host) return;

    const auto ai_target_listener = _networkable_car->car->get_component<AITargetListenerComponent>();
    _networkable_car->car->add_component(std::make_shared<AIBehaviour>(ai_target_listener->get_target()));

    _networkable_car->transmit = true;
    _networkable_car->receive = false;
}

void MultiplayerBehaviour::on_allocation(const AllocationMultiplayerEvent &event) {
    if (event.user_id != _car_id) return;

    _networkable_car->car->remove_component<AIBehaviour>();
    _networkable_car->car->add_component(std::make_shared<DriveInputBehaviour>(_event_manager));
    _networkable_car->car->add_component(std::make_shared<DriveInputControllerBehaviour>(_event_manager, 0));

    // TODO: !!!
    _networkable_car->car->add_child(Global::get_instance()->get_active_scene().get_camera());
//    _networkable_car->car->add_component(ui_velocity_indicator_behaviour);
//    _networkable_car->car->get_component<Sprite>()->set_color(Color(255, 255, 255, 140));

    _networkable_car->transmit = true;
    _networkable_car->receive = false;
}

void MultiplayerBehaviour::on_users(const UsersMultiplayerEvent &event) {
    if (!Global::get_instance()->get_engine().multiplayer_manager->is_host) return;

    for (const auto &id: event.user_ids) {
        if (id != _car_id) continue;
        _networkable_car->car->remove_component<AIBehaviour>();
    }
}

void MultiplayerBehaviour::on_host(const HostMultiplayerEvent &event) {
    auto ai_listener_component = std::make_shared<AITargetListenerComponent>(_event_manager, _targets);
    _networkable_car->car->add_component(ai_listener_component);
    _networkable_car->car->add_component(std::make_shared<AIBehaviour>(ai_listener_component->get_target()));

    _networkable_car->transmit = true;
    _networkable_car->receive = false;
}
