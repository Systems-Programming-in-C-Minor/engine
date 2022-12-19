
#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <memory>
#include <vector>

class Car;
class Scene;
class Vector2d;

class RaceLevel {
public:
    RaceLevel(const std::vector<std::shared_ptr<Car>>& cars, std::vector<Vector2d> targets,
              const std::shared_ptr<Scene>& scene);

    const std::vector<Vector2d> targets;
    const std::vector<std::shared_ptr<Car>> cars;
    const std::shared_ptr<Scene> scene;
};

#endif //GAME_LEVEL_HPP
