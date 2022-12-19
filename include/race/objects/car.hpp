#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"
#include "race/behaviours/drive_behaviour.hpp"

class Car : public GameObject, public DriveBehaviour {
public:
    Car(const std::string &name, const std::string& sprite_path, Vector2d position, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_CAR_HPP
