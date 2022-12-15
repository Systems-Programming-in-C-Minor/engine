#include <iostream>
#include "color.hpp"
#include "gameobject.hpp"
#include "components/sprite.hpp"
#include "global.hpp"
#include "scene.hpp"
#include "components/colliders/boxcollider.hpp"
#include "components/colliders/chaincollider.hpp"
#include "listeners/key_listener.hpp"
#include "listeners/mouse_listener.hpp"
#include "listeners/collider_listener.hpp"
#include "race/behaviours/car_behaviour.hpp"
#include "utils/trigonometry.hpp"
#include "utils/xmlreader.hpp"
#include "uiobjects/text.hpp"
#include "input.hpp"
#include "interfaces/itickable.hpp"
#include "storage/json_properties.hpp"


class KeyMouseListenerComponent : public Component, public KeyListener, public MouseListener, public ColliderListener {
public:
    explicit KeyMouseListenerComponent(EventManager &event_manager) : KeyListener(event_manager),
                                                                      MouseListener(event_manager),
                                                                      ColliderListener(event_manager) {}

    void on_key_pressed(const KeyPressedEvent &event) override {
        if (event.key == P)
            enabled = !enabled;
        if (event.key == C)
            colliders_enabled = !colliders_enabled;
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

    void on_collider_entry(const ColliderEntryEvent &event) override {
        if (colliders_enabled) {
            std::cout << std::endl << "Collider entry a: " << event.collider_a->game_object->get_name() << std::endl;
            std::cout << "Collider entry b: " << event.collider_b->game_object->get_name() << std::endl;
        }
    }

    void on_collider_exit(const ColliderExitEvent &event) override {
        if (colliders_enabled) {
            std::cout << std::endl << "Collider exit a: " << event.collider_a->game_object->get_name() << std::endl;
            std::cout << "Collider exit b: " << event.collider_b->game_object->get_name() << std::endl;
        }
    }

private:
    bool enabled = false;
    bool colliders_enabled = false;
};

class Car : public GameObject {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene,
        const int order_in_layer = 10)
            : GameObject(name, tag) {
        const auto sprite =
                std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false, 1, 10);
        add_component(sprite);

        const auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
        const auto rigid_body = std::make_shared<RigidBody>(*scene, order_in_layer, BodyType::dynamic_body,
                                                            Vector2d{0.f, 1.5f}, 1.f);
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
    global->set_properties(std::make_unique<JsonProperties>("settings.json"));
    Engine &engine_ref = global->get_engine();

    // Setup scene
    const auto scene = std::make_shared<Scene>();

    // Create game objects with component
    const auto track_outer = std::make_shared<GameObject>(
            "track_outer", "track", true,
            Transform{Vector2d{0.f, 0.f}});
    const auto track_inner = std::make_shared<GameObject>(
            "track_inner", "track", true,
            Transform{Vector2d{0.f, 0.f}});

    Sprite sprite1{"./assets/track1.png", Color(0, 0, 0, 255.0), false, false, 1, 1, 6.f};

    track_outer->add_component(std::make_shared<Sprite>(sprite1));

    const auto car = std::make_shared<Car>("player_car", "car", "./assets/blue_car.png", scene);
    const auto car_behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(car_behaviour);

    const auto ui_object = std::make_shared<UIObject>("ui_object", "text", true, Transform{ Vector2d{400.f, -10.f}, Vector2d{}, 0.49f }, 100, 100);
    const auto text = std::make_shared<Text>("name", "tag", true, Transform{ Vector2d{-50.f, 10.f}, Vector2d{}, 1.f }, 20, 5, "text", "./assets/Sans.ttf", 1000, Alignment::CENTER, Color(200, 0, 0, 0), 100);
    ui_object->add_child(text);

    const auto okto = std::make_shared<GameObject>(
            "okto", "okto", true,
            Transform{Vector2d {0.f, 0.f}, Vector2d{0,0}, 0.f, 0.1f});
    const auto okto_sprite = std::make_shared<Sprite>("./assets/sample.png", Color(), false, false, 1, 1, 6.f);
    okto->add_component(okto_sprite);

    car->add_child(okto);

    scene->gameobjects.push_back(track_outer);
    scene->gameobjects.push_back(track_inner);
    scene->gameobjects.push_back(car);
    scene->gameobjects.push_back(okto);
    scene->gameobjects.push_back(ui_object);

    // Add rigid bodies
    const auto track_outer_coll = std::make_shared<ChainCollider>("./assets/track1_outer.xml", false,
                                                                  ColliderNormal::inwards);
    const auto track_outer_rb = std::make_shared<RigidBody>(*scene, 2, BodyType::dynamic_body, Vector2d{0.f, 0.f},
                                                            1.0f);
    track_outer_rb->set_collider(track_outer_coll);
    track_outer->add_component(track_outer_rb);

    const auto track_inner_coll = std::make_shared<ChainCollider>("./assets/track1_inner.xml", false,
                                                                  ColliderNormal::outwards);
    const auto track_inner_rb = std::make_shared<RigidBody>(*scene, 2, BodyType::dynamic_body, Vector2d{0.f, 0.f},
                                                            1.0f);
    track_inner_rb->set_collider(track_inner_coll);
    track_inner->add_component(track_inner_rb);

    // Add listeners
    const auto key_listener_object = std::make_shared<GameObject>("KeyMouseListener", "TestTag", true);
    KeyMouseListenerComponent key_listener{scene->get_event_manager()};
    key_listener_object->add_component(std::make_shared<KeyMouseListenerComponent>(key_listener));
    scene->gameobjects.push_back(key_listener_object);

    engine_ref.load_scene(scene);

    engine_ref.start();
}
