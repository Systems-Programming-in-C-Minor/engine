#include "sdlrenderer.hpp"
#include "color.hpp"
#include "gameobject.hpp"
#include "sdltexture.hpp"
#include "components/sprite.hpp"
#include "global.hpp"
#include "scene.hpp"

int main(int argc, char* argv[])
{
	// TODO Sprite should use a Texture object, not just a string
	// TODO Renderer shouldn't be passed by reference, but retrieved from globals
	// TODO How to get transform into renderer?
	//auto renderer = SdlRenderer(800, 600);
	//SdlTexture texture{ renderer,"./assets/sample.png" };
	//Sprite sprite{ "./assets/sample.png", Color(0,0,0,255.0), false, false, 1, 1 };

	//while(true)
	//{
	//	renderer.clear(Color(0.0, 0.0, 0.0, 255.0));
	//	sprite.render(renderer, false);
	//	renderer.push_to_screen();
	//}

	// Setup engine
	const auto global = Global::get_instance();
	auto engine = std::make_unique<Engine>();
	global->set_engine(std::move(engine));
	Engine& engine_ref = global->get_engine();

	// Create gameobject with sprite component
	const auto game_object = std::make_shared<GameObject>("TestGameObject", "TestTag");
	Sprite sprite{ "./assets/sample.png", Color(0,0,0,255.0), false, false, 1, 1 };
	game_object->add_component(std::make_shared<Sprite>(sprite));
	const auto scene = std::make_shared<Scene>();
	scene->gameobjects.push_back(game_object);

	engine_ref.load_scene(scene);

	engine_ref.start();
}
