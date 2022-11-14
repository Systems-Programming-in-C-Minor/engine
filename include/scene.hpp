#ifndef ENGINE_SCENE_H_Kh3IZygul2
#define ENGINE_SCENE_H_Kh3IZygul2

#include <vector>
#include <memory>

class GameObject;

class Scene
{
public:
	std::vector<std::shared_ptr<GameObject>> gameobjects;
	
	/// Simulates a tick on this scene's gameobjects
	void tick();

	/// Calls the render functions on this scene's gameobjects
	void render();

	Scene();
};

#endif // ENGINE_SCENE_H_Kh3IZygul2