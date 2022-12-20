#ifndef RACE_MULTIPLAYER_BEHAVIOUR_HPP
#define RACE_MULTIPLAYER_BEHAVIOUR_HPP

#include "components/component.hpp"
#include "listeners/multiplayer_listener.hpp"
#include "race/objects/networkables/networkable_car.hpp"
#include <memory>
#include <vector>

class GameObject;

/**
 * @brief Class which defines Multiplayer behaviour.
 */
class MultiplayerBehaviour : public Component, protected MultiplayerListener {
private:
    int _car_id;
    std::shared_ptr<NetworkableCar> _networkable_car;

    EventManager &_event_manager;
    std::vector<Vector2d> _targets;

    std::list<std::shared_ptr<Component>> _active_car_components;
    std::list<std::shared_ptr<GameObject>> _active_car_children;

    void on_user_join(const UserJoinedMultiplayerEvent &event) override;

    void on_user_leave(const UserLeftMultiplayerEvent &event) override;

    void on_allocation(const AllocationMultiplayerEvent &event) override;

    void on_users(const UsersMultiplayerEvent &event) override;

    void on_host(const HostMultiplayerEvent &event) override;

    void on_parent_set() override;

public:
    /**
     * @brief Constructor.
     * @param event_manager The EventManager the behaviour will use to receive events.
     * @param car_id The id of the car.
     * @param targets Targets for the AI to track.
     * @param active_car_components Components to add on the actively controller car.
     * @param active_car_children GameObjects to add on the actively controller car.
     */
    explicit MultiplayerBehaviour(
            EventManager &event_manager,
            int car_id,
            std::vector<Vector2d> targets,
            std::list<std::shared_ptr<Component>> active_car_components = {},
            std::list<std::shared_ptr<GameObject>> active_car_children = {}
    );

    /**
     * @brief Virtual destructor.
     */
    ~MultiplayerBehaviour() override = default;
};

#endif //RACE_MULTIPLAYER_BEHAVIOUR_HPP