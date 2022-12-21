#include "race/behaviours/multiplayer_behaviour.hpp"

#include <utility>
#include "race/objects/car.hpp"
#include "race/behaviours/ai_target_behaviour.hpp"
#include "global.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/behaviours/drive_input_controller_behaviour.hpp"


MultiplayerBehaviour::MultiplayerBehaviour(EventManager &event_manager,
                                           int car_id,
                                           std::vector<Vector2d> targets,
                                           std::list<std::shared_ptr<Component>> active_car_components,
                                           std::list<std::shared_ptr<GameObject>> active_car_children) :
        MultiplayerListener(event_manager),
        _car_id(car_id),
        _game_is_running(false),
        _event_manager(event_manager),
        _targets(std::move(targets)),
        _active_car_components(std::move(active_car_components)),
        _active_car_children(std::move(active_car_children)) {}

void MultiplayerBehaviour::on_user_join(const UserJoinedMultiplayerEvent &event) {
    if (event.user_id != _car_id) return;
    if (!Global::get_instance()->get_engine().multiplayer_manager->is_host) return;

    _networkable_car->car->remove_component<AIBehaviour>();
    _networkable_car->car->get_component<AITargetBehaviour>()->reset();

    _networkable_car->transmit = false;
    _networkable_car->receive = true;

    if (_game_is_running) {
        Global::get_instance()->get_engine().multiplayer_manager->start_game();
    }
}

void MultiplayerBehaviour::on_user_leave(const UserLeftMultiplayerEvent &event) {
    if (event.user_id != _car_id) return;
    if (!Global::get_instance()->get_engine().multiplayer_manager->is_host) return;

    const auto ai_target_listener = _networkable_car->car->get_component<AITargetBehaviour>();
    _networkable_car->car->add_component(std::make_shared<AIBehaviour>(ai_target_listener->get_target()));

    _networkable_car->transmit = true;
    _networkable_car->receive = false;
}

void MultiplayerBehaviour::on_allocation(const AllocationMultiplayerEvent &event) {
    if (event.user_id != _car_id) return;

    _networkable_car->car->remove_component<AIBehaviour>();
    _networkable_car->car->add_component(std::make_shared<DriveInputBehaviour>(_event_manager));
    _networkable_car->car->add_component(std::make_shared<DriveInputControllerBehaviour>(_event_manager, 0));

    for (const auto &component: _active_car_components) {
        _networkable_car->car->add_component(component);
    }

    for (const auto &game_object: _active_car_children) {
        _networkable_car->car->add_child(game_object);
    }

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
    auto ai_listener_component = std::make_shared<AITargetBehaviour>(_event_manager, _targets);
    _networkable_car->car->add_component(ai_listener_component);
    _networkable_car->car->add_component(std::make_shared<AIBehaviour>(ai_listener_component->get_target()));

    _networkable_car->transmit = true;
    _networkable_car->receive = false;
}

void MultiplayerBehaviour::on_parent_set() {
    const auto car = reinterpret_cast<Car *>(game_object);
    _networkable_car = std::make_shared<NetworkableCar>(car, false, true);

    Global::get_instance()->get_engine().multiplayer_manager->register_networkable(_networkable_car);
}

void MultiplayerBehaviour::on_start_game(const StartGameMultiplayerEvent &event) {
    _game_is_running = true;
}

void MultiplayerBehaviour::on_stop_game(const StopGameMultiplayerEvent &event) {
    _game_is_running = false;
}
