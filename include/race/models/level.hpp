
#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <memory>
#include <vector>

class Car;
class Scene;
class Vector2d;

/**
 * @brief Class representing a Race level.
 */
class RaceLevel {
public:
    /**
     * @brief Constructor.
     * @param cars The cars which will be loaded into the level.
     * @param targets The targets for the cars which will be loaded into the level.
     * @param scene The scene in which the objects will be loaded.
     */
    RaceLevel(const std::vector<std::shared_ptr<Car>>& cars, std::vector<Vector2d> targets,
              const std::shared_ptr<Scene>& scene);

    const std::vector<Vector2d> targets;
    const std::vector<std::shared_ptr<Car>> cars;
    const std::shared_ptr<Scene> scene;
};

#endif //GAME_LEVEL_HPP
