#ifndef ENGINE_SCENE_H_Kh3IZygul2
#define ENGINE_SCENE_H_Kh3IZygul2

#include <vector>
#include <memory>
#include "components/rigidbody.hpp"
#include "managers/event_manager.hpp"
#include "camera.hpp"

class Camera;
class IRenderer;
class b2World;
class b2Vec2;
class CollisionHandler;

class GameObject;

class Scene {
    friend class RigidBody;
private:
    const std::unique_ptr<EventManager> _event_manager;
    const std::unique_ptr<b2World> _world;
    const std::unique_ptr<CollisionHandler> _collision_handler;
    std::shared_ptr<Camera> _camera;
public:
    std::vector<std::shared_ptr<GameObject>> gameobjects;

    /**
     * Simulates a tick on this scene's gameobjects
     */
    virtual void tick();

    void tick_world();

    /**
     * Calls the render functions on this scene's gameobjects
     */
    virtual void render() const;

    [[nodiscard]] EventManager &get_event_manager() const;

    [[nodiscard]] std::shared_ptr<Camera> get_camera() const;

    Scene(std::shared_ptr<Camera> camera = std::make_shared<Camera>());    

    virtual ~Scene();
};

#endif // ENGINE_SCENE_H_Kh3IZygul2