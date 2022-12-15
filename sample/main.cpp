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
#include "race/behaviours/ai_behaviour.hpp"
#include "utils/trigonometry.hpp"
#include "utils/xmlreader.hpp"
#include "uiobjects/text.hpp"
#include "input.hpp"
#include "storage/json_properties.hpp"
#include "listeners/joystick_listener.hpp"
#include "listeners/ai_listener.hpp"


class KeyMouseListenerComponent
        : public Component, public KeyListener, public MouseListener, public ColliderListener, public JoystickListener {
public:
    explicit KeyMouseListenerComponent(EventManager &event_manager) : KeyListener(event_manager),
                                                                      MouseListener(event_manager),
                                                                      ColliderListener(event_manager),
                                                                      JoystickListener(event_manager) {}

    void on_key_pressed(const KeyPressedEvent &event) override {
        if (event.key == P)
            enabled = !enabled;
        if (event.key == C)
            colliders_enabled = !colliders_enabled;
        if (enabled)
            std::cout << "Pressed key: " << event.key << std::endl;
    }

    void on_key_hold(const KeyHoldEvent &event) override {
        if (enabled)
            std::cout << "Hold key: " << event.key << std::endl;
    }

    void on_key_released(const KeyReleasedEvent &event) override {
        if (enabled)
            std::cout << "Released key: " << event.key << std::endl;
    }

    void on_mouse_moved(const MouseMovedEvent &event) override {
        if (enabled)
            std::cout << "Moved mouse: " << event.x << " " << event.y << std::endl;

    }

    void on_mouse_pressed(const MousePressedEvent &event) override {
        if (enabled)
            std::cout << "Pressed mouse: " << event.button << std::endl;

    }

    void on_mouse_released(const MouseReleasedEvent &event) override {
        if (enabled)
            std::cout << "Released mouse: " << event.button << std::endl;
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

    void on_button_pressed(const JoystickButtonPressedEvent &event) override {
        if (enabled)
            std::cout << "Joystick button pressed: " << event.button << std::endl;
    }

    void on_button_hold(const JoystickButtonHoldEvent &event) override {
        if (enabled)
            std::cout << "Joystick button hold: " << event.button << std::endl;
    }

    void on_button_released(const JoystickButtonReleasedEvent &event) override {
        if (enabled)
            std::cout << "Joystick button released: " << event.button << std::endl;
    }

    void on_axis_changed(const JoystickAxisChangedEvent &event) override {
        if (enabled)
            std::cout << "Joystick axis changed: " << event.axis << " (" << event.value << ")" << std::endl;
    }

//    void on_axis_current(const JoystickAxisCurrentEvent &event) override {
//        if (enabled)
//            std::cout << "Joystick axis current: " << event.axis << "(" << event.value << ")" << std::endl;
//    }

private:
    bool enabled = false;
    bool colliders_enabled = false;
};

class Car : public GameObject {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene,
        const int order_in_layer = 10, Vector2d position = Vector2d())
            : GameObject(name, tag) {
        const auto sprite = std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false, 1, 10);
        add_component(sprite);

        const auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
        const auto rigid_body = std::make_shared<RigidBody>(*scene, order_in_layer, BodyType::dynamic_body, position, 1.f);

        rigid_body->set_mass(1600.f);
        rigid_body->set_collider(collider);
        add_component(rigid_body);
        transform.set_scale(0.5f);
        transform.set_angle(degrees_to_radians(90));
    }
};

class PlayerCarBehaviour : public CarBehaviour, public KeyListener, public JoystickListener {
public:
    explicit PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager),
                                                               JoystickListener(event_manager) {}

    void on_key_pressed(const KeyPressedEvent &event) override {
        switch (event.key) {
            case EQUAL:
                game_object->transform.set_scale(game_object->transform.get_scale() + 0.01f);
                break;
            case MIN:
                game_object->transform.set_scale(game_object->transform.get_scale() - 0.01f);
                break;
            case B:
                std::cout << game_object->transform.get_position() << std::endl;
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

    void on_axis_current(const JoystickAxisCurrentEvent &event) override {
        switch (event.axis) {
            case LeftJoystickX: {
                if (std::abs(event.value) > 0.1f) {
                    turn(-event.value);
                }
                break;
            }
            case LeftTrigger: {
                if (event.value > -0.9) {
                    drive_backwards((event.value + 1.0f) / 2);
                }
                break;
            }
            case RightTrigger: {
                if (event.value > -0.9) {
                    drive_forwards((event.value + 1.0f) / 2);
                }
                break;
            }
            case LeftJoystickY:
            case RightJoystickX:
            case RightJoystickY:
                break;
        }
    }

    void on_button_hold(const JoystickButtonHoldEvent &event) override {
        if (event.button == LeftButton) {
            brake();
        }
    }

    void on_key_released(const KeyReleasedEvent &event) override {}
};

class Target : public GameObject {
public:
    Target(const std::string &name, const std::string &tag, Transform transform = Transform{Vector2d()})
            : GameObject(name, tag, true, transform) {
        const auto sprite = std::make_shared<Sprite>("./assets/sample.png", Color(), false, false, 1, 10);

        add_component(sprite);
    }
};

class TargetFactory {
public:
    int counter = 0;

    std::vector<std::shared_ptr<Target>> make_targets(std::vector<Vector2d> &vectors){
        std::vector<std::shared_ptr<Target>> res;

        for(auto vector: vectors){
            auto target = std::make_shared<Target>("Target"+counter,"target", Transform{vector});
            res.emplace_back(target);
            counter++;
        }

        return res;
    };
};

class AITargetListenerComponent : public Component, public AIListener {
public:
    explicit AITargetListenerComponent(EventManager &event_manager) : AIListener(event_manager) {};

    std::vector<std::shared_ptr<Target>> targets;

    int _target_index = 0;

    void on_target_reached(const AITargetReachedEvent &event) override {
        auto test = game_object->get_component<AIBehaviour>()->game_object;
        if(event.ai_behaviour.game_object != test)
            return;

        _target_index++;
        if(targets.size() <= _target_index){
            _target_index = 0;
        }
        event.ai_behaviour.set_target(targets[_target_index]);
    };
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

    const auto car = std::make_shared<Car>("player_car", "car", "./assets/blue_car.png", scene, 10, Vector2d{-6.f, 0.f});
    const auto car_behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(car_behaviour);

    TargetFactory tf;
    std::vector<Vector2d> vector_targets;
    {
        vector_targets.emplace_back(Vector2d{-60.f, -72.f});
        vector_targets.emplace_back(Vector2d{-74.f, -53.f});
        vector_targets.emplace_back(Vector2d{-60.f, -34.f});
        vector_targets.emplace_back(Vector2d{-10.f, -6.f});
        vector_targets.emplace_back(Vector2d{-13.f, 32.f});
        vector_targets.emplace_back(Vector2d{-65.f, 38.f});
        vector_targets.emplace_back(Vector2d{-72.f, 62.f});
        vector_targets.emplace_back(Vector2d{-52.f, 73.f});
        vector_targets.emplace_back(Vector2d{64.f, 73.f});
        vector_targets.emplace_back(Vector2d{77.f, 57.f});
        vector_targets.emplace_back(Vector2d{22.f, 37.f});
        vector_targets.emplace_back(Vector2d{16.f, -34.f});
        vector_targets.emplace_back(Vector2d{49.f, -39.f});
        vector_targets.emplace_back(Vector2d{34.f, 18.f});
        vector_targets.emplace_back(Vector2d{72.f, 20.f});
        vector_targets.emplace_back(Vector2d{73.f, -66.f});
    }

    auto targets = tf.make_targets(vector_targets);

    const auto ai_car = std::make_shared<Car>("ai_car", "ai-car", "./assets/blue_car.png", scene, 10, Vector2d{14, -76} );
    ai_car->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car->add_component(ai_listener_component);
    ai_listener_component->targets = targets;

    const auto ai_car2 = std::make_shared<Car>("ai_car2", "ai-car", "./assets/red_car.png", scene, 10,Vector2d{20, -72});
    ai_car2->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component2 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car2->add_component(ai_listener_component2);
    ai_listener_component2->targets = targets;

    const auto ai_car3 = std::make_shared<Car>("ai_car3", "ai-car", "./assets/green_car.png", scene, 10,Vector2d{26, -76});
    ai_car3->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component3 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car3->add_component(ai_listener_component3);
    ai_listener_component3->targets = targets;

    const auto ai_car4 = std::make_shared<Car>("ai_car4", "ai-car", "./assets/pink_car.png", scene, 10,Vector2d{31, -72});
    ai_car4->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component4 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car4->add_component(ai_listener_component4);
    ai_listener_component4->targets = targets;

    const auto ai_car5 = std::make_shared<Car>("ai_car5", "ai-car", "./assets/orange_car.png", scene, 10, Vector2d{38, -76});
    ai_car5->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component5 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car5->add_component(ai_listener_component5);
    ai_listener_component5->targets = targets;

    const auto ai_car6 = std::make_shared<Car>("ai_car6", "ai-car", "./assets/yellow_car.png", scene, 10, Vector2d{43, -72});
    ai_car6->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component6 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car6->add_component(ai_listener_component6);
    ai_listener_component6->targets = targets;

    const auto ui_object = std::make_shared<UIObject>("ui_object", "text", true, Transform{Vector2d{400.f, -10.f}, Vector2d{}, 20.0f, 0.49f} ,100, 100);
    Text text{"name", "tag", true, Transform{Vector2d{-50.f, 10.f}, Vector2d{}, 1.F, 1.f}, 20,5, "text", "./assets/Sans.ttf", 1000, Alignment::CENTER, Color(200, 0, 0, 0), 100};
    ui_object->add_child(std::make_shared<Text>(text));

    scene->gameobjects.push_back(track_outer);
    scene->gameobjects.push_back(track_inner);
    scene->gameobjects.push_back(car);
    scene->gameobjects.push_back(ai_car);
    scene->gameobjects.push_back(ui_object);

    scene->gameobjects.push_back(ai_car2);
    scene->gameobjects.push_back(ai_car3);
    scene->gameobjects.push_back(ai_car4);
    scene->gameobjects.push_back(ai_car5);
    scene->gameobjects.push_back(ai_car6);

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
