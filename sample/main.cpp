#include <iostream>
#include "color.hpp"
#include "gameobject.hpp"
#include "components/sprite.hpp"
#include "global.hpp"
#include "scene.hpp"
#include "components/colliders/boxcollider.hpp"
#include "listeners/key_listener.hpp"
#include "listeners/mouse_listener.hpp"
#include "input.hpp"
#include "interfaces/itickable.hpp"

class InputScript : public Component, public ITickable {
    Input input;

    void tick(GameObject &gameobject){

        if(input.get_mouse_button(BUTTON_LEFT)){
            std::cout << input.mouse_position() << std::endl;
        }

        if (input.get_key_down(A)){
            std::cout << "Pressed A key" << std::endl;
        }
    }
};

class KeyListenerComponent : public Component, public KeyListener {
public:
    explicit KeyListenerComponent(EventManager &event_manager) : KeyListener(event_manager) {}

    void on_key_pressed(const KeyPressedEvent &event) override {
        std::cout << "Pressed key: " << event.key << "\n";
    }

    void on_key_hold(const KeyHoldEvent &event) override {
        std::cout << "Hold key: " << event.key << "\n";
    }

    void on_key_released(const KeyReleasedEvent &event) override {
        std::cout << "Released key: " << event.key << "\n";
    }
};

class MouseListenerComponent : public Component, public MouseListener {
public:
    explicit MouseListenerComponent(EventManager &event_manager) : MouseListener(event_manager) {}

    void on_mouse_moved(const MouseMovedEvent &event) override {
        std::cout << "Moved mouse: " << event.x << " " << event.y << "\n";

    }

    void on_mouse_pressed(const MousePressedEvent &event) override {
        std::cout << "Pressed mouse: " << event.button << "\n";

    }

    void on_mouse_released(const MouseReleasedEvent &event) override {
        std::cout << "Released mouse: " << event.button << "\n";

    }
};

int main(int argc, char *argv[]) {
    // Setup engine
    const auto global = Global::get_instance();
    auto engine = std::make_unique<Engine>();
    global->set_engine(std::move(engine));
    Engine &engine_ref = global->get_engine();

    // Create gameobject with sprite component
    const auto game_object1 = std::make_shared<GameObject>(
            "TestGameObject", "TestTag", true,
            Transform{Vector2d{0.f, 0.f}, 0.0f, 0.4f});
    const auto game_object2 = std::make_shared<GameObject>(
            "TestGameObject", "TestTag", true,
            Transform{Vector2d{1.f, 1.f}, 1.1f, 0.2f});
    const auto game_object3 = std::make_shared<GameObject>(
            "TestGameObject", "TestTag", true,
            Transform{Vector2d{-1.f, -1.f}, 2.0f, 0.3f});

    Sprite sprite1{"./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, 1};
    Sprite sprite2{"./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, 1};
    Sprite sprite3{"./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, 1};

    game_object1->add_component(std::make_shared<Sprite>(sprite1));
    game_object2->add_component(std::make_shared<Sprite>(sprite2));
    game_object3->add_component(std::make_shared<Sprite>(sprite3));
    game_object3->add_component(std::make_shared<InputScript>());

    const auto scene = std::make_shared<Scene>();

    // Try colliders
    auto collider = std::make_shared<BoxCollider>(4.f, 4.f);
    auto rigid_body = std::make_shared<RigidBody>(*scene, BodyType::static_body, Vector2d{ 0.f, 0.f }, 1.0f);
    rigid_body->set_collider(collider);
    game_object1->add_component(rigid_body);

    scene->gameobjects.push_back(game_object1);
    scene->gameobjects.push_back(game_object2);
    scene->gameobjects.push_back(game_object3);

    // Add listeners
    const auto key_listener_object = std::make_shared<GameObject>("KeyListener", "TestTag", true);
    KeyListenerComponent key_listener{scene->get_event_manager()};
    key_listener_object->add_component(std::make_shared<KeyListenerComponent>(key_listener));
    scene->gameobjects.push_back(key_listener_object);

    const auto mouse_listener_object = std::make_shared<GameObject>("MouseListener", "TestTag", true);
    MouseListenerComponent mouse_listener{scene->get_event_manager()};
    mouse_listener_object->add_component(std::make_shared<MouseListenerComponent>(mouse_listener));
    scene->gameobjects.push_back(mouse_listener_object);

    engine_ref.load_scene(scene);

    engine_ref.start();
}
