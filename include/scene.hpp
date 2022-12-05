#ifndef ENGINE_SCENE_H_Kh3IZygul2
#define ENGINE_SCENE_H_Kh3IZygul2

#include <vector>
#include <memory>
#include "components/rigidbody.hpp"
#include "managers/event_manager.hpp"

class IRenderer;
class b2World;
class b2Vec2;

class GameObject;

class Scene {
private:
    const std::unique_ptr<EventManager> _event_manager;
    const std::unique_ptr<b2World> _world;
    friend class RigidBody;

public:
    std::vector<std::shared_ptr<GameObject>> gameobjects;

    /**
     * Simulates a tick on this scene's gameobjects
     */
    virtual void tick();

    /**
     * Calls the render functions on this scene's gameobjects
     *
     * @param[in] renderer Reference to the active renderer
     */
    virtual void render(IRenderer &renderer) const;

    Scene();

    virtual ~Scene();
};

#endif // ENGINE_SCENE_H_Kh3IZygul2