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

    void on_user_join(const UserJoinedMultiplayerEvent &event) override;

    void on_user_leave(const UserLeftMultiplayerEvent &event) override;

    void on_allocation(const AllocationMultiplayerEvent &event) override;

    void on_users(const UsersMultiplayerEvent &event) override;

    void on_host(const HostMultiplayerEvent &event) override;

public:
    /**
     * @brief Constructor.
     * @param event_manager The EventManager the behaviour will use to receive events.
     * @param networkable_car The NetworkableCar the behaviour will control.
     * @param car_id The id of the car.
     */
    explicit MultiplayerBehaviour(EventManager &event_manager,
                                  std::shared_ptr<NetworkableCar> networkable_car,
                                  int car_id,
                                  std::vector<Vector2d> targets
    );

    /**
     * @brief Virtual destructor.
     */
    ~MultiplayerBehaviour() override = default;
};

#endif //RACE_MULTIPLAYER_BEHAVIOUR_HPP