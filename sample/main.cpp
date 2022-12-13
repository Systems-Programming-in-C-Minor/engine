#include <iostream>
#include "sdlrenderer.hpp"
#include "color.hpp"
#include "gameobject.hpp"
#include "components/sprite.hpp"
#include "global.hpp"
#include "scene.hpp"
#include "components/colliders/boxcollider.hpp"
#include "components/colliders/chaincollider.hpp"
#include "listeners/key_listener.hpp"
#include "listeners/mouse_listener.hpp"
#include "race/behaviours/car_behaviour.hpp"
#include "utils/trigonometry.hpp"
#include "utils/xmlreader.hpp"

class KeyMouseListenerComponent : public Component, public KeyListener, public MouseListener {
public:
    explicit KeyMouseListenerComponent(EventManager &event_manager) : KeyListener(event_manager),
                                                                      MouseListener(event_manager) {}

    void on_key_pressed(const KeyPressedEvent &event) override {
        if (event.key == P)
            enabled = !enabled;
        if (enabled)
            std::cout << "Pressed key: " << event.key << "\n";
    }

    void on_key_hold(const KeyHoldEvent &event) override {
        if (enabled)
            std::cout << "Hold key: " << event.key << "\n";
    }

    void on_key_released(const KeyReleasedEvent &event) override {
        if (enabled)
            std::cout << "Released key: " << event.key << "\n";
    }

    void on_mouse_moved(const MouseMovedEvent &event) override {
        if (enabled)
            std::cout << "Moved mouse: " << event.x << " " << event.y << "\n";

    }

    void on_mouse_pressed(const MousePressedEvent &event) override {
        if (enabled)
            std::cout << "Pressed mouse: " << event.button << "\n";

    }

    void on_mouse_released(const MouseReleasedEvent &event) override {
        if (enabled)
            std::cout << "Released mouse: " << event.button << "\n";
    }

private:
    bool enabled = false;
};

class Car : public GameObject {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene, const int order_in_layer = 10)
            : GameObject(name, tag) {
        auto sprite =
                std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false, 1, 10);
        add_component(sprite);

        auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
        auto rigid_body = std::make_shared<RigidBody>(*scene, order_in_layer, BodyType::dynamic_body, Vector2d{0.f, 1.5f}, 1.f);
        rigid_body->set_mass(1600.f);
        rigid_body->set_collider(collider);
        add_component(rigid_body);
        transform.set_scale(.5f);
        transform.set_angle(degrees_to_radians(90));
    }
};

class PlayerCarBehaviour : public CarBehaviour, public KeyListener {
public:
    explicit PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager) {}

    void on_key_pressed(const KeyPressedEvent &event) override {
        switch (event.key) {
            case EQUAL:
                game_object->transform.set_scale(game_object->transform.get_scale() + 0.01f);
                break;
            case MIN:
                game_object->transform.set_scale(game_object->transform.get_scale() - 0.01f);
                break;
        }
    }

    void on_key_hold(const KeyHoldEvent &event) override {
        switch (event.key) {
            case W: {
                drive_forwards();
                break;
            }
            case S: {
                drive_backwards();
                break;
            }
            case A: {
                turn_left();
                break;
            }
            case D: {
                turn_right();
                break;
            }
            case SPACE: {
                brake();
                break;
            }
            case UP: {
                Vector2d pos_up{game_object->transform.get_position().x,
                                game_object->transform.get_position().y + 0.01f};
                game_object->transform.set_position(pos_up);
                break;
            }
            case DOWN: {
                Vector2d pos_down{game_object->transform.get_position().x,
                                  game_object->transform.get_position().y - 0.01f};
                game_object->transform.set_position(pos_down);
                break;
            }
            case LEFT: {
                Vector2d pos_left{game_object->transform.get_position().x - 0.01f,
                                  game_object->transform.get_position().y};
                game_object->transform.set_position(pos_left);
                break;
            }
            case RIGHT: {
                Vector2d pos_right{game_object->transform.get_position().x + 0.01f,
                                   game_object->transform.get_position().y};
                game_object->transform.set_position(pos_right);
                break;
            }
        }
    }

    void on_key_released(const KeyReleasedEvent &event) override {}
};

int main() {
    // Setup engine
    const auto global = Global::get_instance();
    auto engine = std::make_unique<Engine>();
    global->set_engine(std::move(engine));
    Engine &engine_ref = global->get_engine();

    // Create gameobject with sprite component
    const auto game_object1 = std::make_shared<GameObject>(
            "TestGameObject", "TestTag", true,
            Transform{Vector2d{0.f, 0.f}, 0.0f, 0.5f});
    const auto game_object2 = std::make_shared<GameObject>(
            "TestGameObject", "TestTag", true,
            Transform{Vector2d{1.f, 1.f}, 1.1f, 0.3f});
    const auto game_object3 = std::make_shared<GameObject>(
            "TestGameObject", "TestTag", true,
            Transform{Vector2d{-1.f, -1.f}, 2.0f, 0.4f});

    Sprite sprite1{"./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, 5};
    Sprite sprite2{"./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, 2};
    Sprite sprite3{"./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, -1};

    game_object1->add_component(std::make_shared<Sprite>(sprite1));
    game_object2->add_component(std::make_shared<Sprite>(sprite2));
    game_object3->add_component(std::make_shared<Sprite>(sprite3));

    const auto scene = std::make_shared<Scene>();

    scene->gameobjects.push_back(game_object1);
    scene->gameobjects.push_back(game_object2);
    scene->gameobjects.push_back(game_object3);

    // Add listeners
    const auto key_listener_object = std::make_shared<GameObject>("KeyMouseListener", "TestTag", true);
    KeyMouseListenerComponent key_listener{scene->get_event_manager()};
    key_listener_object->add_component(std::make_shared<KeyMouseListenerComponent>(key_listener));
    scene->gameobjects.push_back(key_listener_object);

    auto car = std::make_shared<Car>("player-car", "car", "./assets/blue_car.png", scene);
    auto behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(behaviour);
    scene->gameobjects.push_back(car);

//    auto chaincollider = std::make_shared<ChainCollider>("./assets/track1_outer.xml");
//    auto chain_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{ 2.f, 2.f }, 1.0f);
//    chain_rigidbody->set_collider(chaincollider);
//    game_object2->add_component(chain_rigidbody);


    engine_ref.load_scene(scene);

    engine_ref.start();
}
