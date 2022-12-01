#ifndef ENGINE_SCENE_H_Kh3IZygul2
#define ENGINE_SCENE_H_Kh3IZygul2

#include <vector>
#include <memory>
#include "box2d/box2d.h"
#include "components/rigidbody.hpp"

class IRenderer;

class GameObject;

class Scene {
private:
    const std::unique_ptr<b2World> _world = std::make_unique<b2World>(b2Vec2(0.0f, 0.0f));
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

private:
    const std::unique_ptr<b2World> _world = std::make_unique<b2World>(b2Vec2(0.0f, 0.0f));

    friend class RigidBody;

    virtual ~Scene();
};

#endif // ENGINE_SCENE_H_Kh3IZygul2