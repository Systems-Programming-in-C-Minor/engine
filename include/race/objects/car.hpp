#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"
#include "race/behaviours/drive_behaviour.hpp"

/**
 * @brief Class representing a Car object.
 */
class Car : public GameObject, public DriveBehaviour {
public:
    /**
     * @brief Constructor.
     * @param name The name of the car.
     * @param sprite_path The sprite path of the car.
     * @param position The initial position of the car.
     * @param scene The scene the Car will be loaded into.
     * @param is_enabled Boolean value whether or not the car is enabled.
     */
    Car(const std::string &name, const std::string& sprite_path, Vector2d position, const std::shared_ptr<Scene> &scene, bool is_enabled = true);
};

#endif //GAME_CAR_HPP
