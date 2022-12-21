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
    /**
    * @brief The RigidBody friend class.
    */
    friend class RigidBody;
private:
    const std::unique_ptr<EventManager> _event_manager;
    const std::unique_ptr<b2World> _world;
    const std::unique_ptr<CollisionHandler> _collision_handler;
    std::shared_ptr<Camera> _camera;
    const std::string _name;
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
     * @brief Getter method for the name.
     * @return The current std::string name object.
     */
    [[nodiscard]] std::string get_name() const;

    /**
     * @brief Setter method for the camera.
     * @param camera The Camera object which will be set.
     */
    void set_camera(std::shared_ptr<Camera> camera);

    /**
     * @brief Constructor.
     * @param camera The current Camera object.
     * @param name The name of the Scene (optionally).
     */
    Scene(std::shared_ptr<Camera> camera = std::make_shared<Camera>(), std::string  name = "");

    /**
     * @brief Virtual destructor.
     */
    virtual ~Scene();
};

#endif // ENGINE_SCENE_H_Kh3IZygul2