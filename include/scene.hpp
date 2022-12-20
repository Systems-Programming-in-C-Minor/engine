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

/**
 * @brief Class representing a scene which can be rendered by the Camera.
 */
class Scene {
    friend class RigidBody;
private:
    const std::unique_ptr<EventManager> _event_manager;
    const std::unique_ptr<b2World> _world;
    const std::unique_ptr<CollisionHandler> _collision_handler;
    std::shared_ptr<Camera> _camera;
public:
    /**
    * @brief A vector containing the game objects of the Scene (GameObject).
    */
    std::vector<std::shared_ptr<GameObject>> gameobjects;

    /**
     * @brief Simulates a tick on this scene's gameobjects.
     */
    virtual void tick();

    /**
     * @brief Simulates a tick on this scene's world.
     */
    void tick_world();

    /**
     * @brief Calls the render functions on this scene's gameobjects.
     */
    virtual void render() const;

    /**
     * @brief Getter method for the event manager.
     * @return The current EventManager object.
     */
    [[nodiscard]] EventManager &get_event_manager() const;

    /**
     * @brief Getter method for the camera.
     * @return The current Camera object.
     */
    [[nodiscard]] std::shared_ptr<Camera> get_camera() const;

    /**
     * @brief Setter method for the camera.
     * @param camera The Camera object which will be set.
     */
    void set_camera(std::shared_ptr<Camera> camera);

    /**
     * @brief Constructor.
     * @param camera The current Camera object.
     */
    Scene(std::shared_ptr<Camera> camera = std::make_shared<Camera>());

    /**
     * @brief Virtual destructor.
     */
    virtual ~Scene();
};

#endif // ENGINE_SCENE_H_Kh3IZygul2