#include "race/models/level.hpp"
#include <utility>
#include <vector2d.hpp>

RaceLevel::RaceLevel(const std::vector<std::shared_ptr<Car>>& cars, std::vector<Vector2d> targets,
                     const std::shared_ptr<Scene>& scene) : scene(scene), targets(std::move(targets)), cars(cars) {}
