
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

    /**
     * @brief A vector containing the targets (Vector2d objects) of the RaceLevel.
     */
    const std::vector<Vector2d> targets;

    /**
     * @brief A vector containing the cars (Car objects) of the RaceLevel.
     */
    const std::vector<std::shared_ptr<Car>> cars;

    /**
     * @brief A shared pointer to the Scene of the RaceLevel.
     */
    const std::shared_ptr<Scene> scene;
};

#endif //GAME_LEVEL_HPP
