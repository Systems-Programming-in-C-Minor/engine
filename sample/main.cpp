#include "sdlrenderer.hpp"
#include "color.hpp"
#include "gameobject.hpp"
#include "components/sprite.hpp"
#include "global.hpp"
#include "scene.hpp"
#include "input.hpp"

int main(int argc, char* argv[])
{
	// Setup engine
	const auto global = Global::get_instance();
	auto engine = std::make_unique<Engine>();
	global->set_engine(std::move(engine));
	Engine& engine_ref = global->get_engine();

	// Create gameobject with sprite component
	const auto game_object1 = std::make_shared<GameObject>("TestGameObject", "TestTag", true, Transform{ Vector2d{ 0.f, 0.f }, 0.0f, 0.4f });
	const auto game_object2 = std::make_shared<GameObject>("TestGameObject", "TestTag", true, Transform{ Vector2d{ 1.f, 1.f }, 1.1f, 0.2f });
	const auto game_object3 = std::make_shared<GameObject>("TestGameObject", "TestTag", true, Transform{ Vector2d{ -1.f, -1.f }, 2.0f, 0.3f });
	Sprite sprite1{ "./assets/sample.png", Color(0,0,0,255.0), false, false, 1, 1 };
	Sprite sprite2{ "./assets/sample.png", Color(0,0,0,255.0), false, false, 1, 1 };
	Sprite sprite3{ "./assets/sample.png", Color(0,0,0,255.0), false, false, 1, 1 };
	game_object1->add_component(std::make_shared<Sprite>(sprite1));
	game_object2->add_component(std::make_shared<Sprite>(sprite2));
	game_object3->add_component(std::make_shared<Sprite>(sprite3));
	const auto scene = std::make_shared<Scene>();
	scene->gameobjects.push_back(game_object1);
	scene->gameobjects.push_back(game_object2);
	scene->gameobjects.push_back(game_object3);

	engine_ref.load_scene(scene);

	engine_ref.start();
}
