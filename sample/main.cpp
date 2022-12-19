#include <iostream>

#include "camera.hpp"
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
#include "race/behaviours/drive_behaviour.hpp"
#include "race/behaviours/ai_behaviour.hpp"
#include "utils/trigonometry.hpp"
#include "utils/xmlreader.hpp"
#include "uiobject.hpp"
#include "components/text.hpp"
#include "input.hpp"
#include "storage/json_properties.hpp"
#include "listeners/joystick_listener.hpp"
#include "listeners/ai_listener.hpp"
#include "race/objects/car.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/behaviours/drive_input_controller_behaviour.hpp"

const auto scene = std::make_shared<Scene>();
const auto scene2 = std::make_shared<Scene>();

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
        if (event.key == ALT_LEFT)
            _ALT = true;
        if (event.key == ENTER && _ALT)
            Global::get_instance()->get_engine().get_renderer()->toggle_fullscreen();
        if (event.key == D && _ALT)
            Global::get_instance()->get_engine().get_renderer()->toggle_debug_mode();
        if (event.key == NUM_5 && _ALT) {   
            Global::get_instance()->get_engine().load_scene(scene2);
            std::cout << "test" << std::endl;
        }
        if (event.key == NUM_4 && _ALT)
            Global::get_instance()->get_engine().load_scene(scene);
        if (event.key == RIGHT && _ALT) {
	        const int ticks = Global::get_instance()->get_engine().get_ticks_per_second();
            (ticks < 1000) ? Global::get_instance()->get_engine().set_ticks_per_second(ticks + 10) : void();
        }
        if (event.key == LEFT && _ALT) {
            const int ticks = Global::get_instance()->get_engine().get_ticks_per_second();
            (ticks > 10) ? Global::get_instance()->get_engine().set_ticks_per_second(ticks - 10) : void();
        }
        if (enabled)
            std::cout << "Pressed key: " << event.key << std::endl;
    }

    void on_key_hold(const KeyHoldEvent &event) override {
        if (enabled)
            std::cout << "Hold key: " << event.key << std::endl;
    }

    void on_key_released(const KeyReleasedEvent &event) override {
        if (event.key == ALT_LEFT)
            _ALT = false;
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
            std::cout << "Joystick " << event.joystick_id << " button pressed: " << event.button << std::endl;
    }

    void on_button_hold(const JoystickButtonHoldEvent &event) override {
        if (enabled)
            std::cout << "Joystick " << event.joystick_id << " button hold: " << event.button << std::endl;
    }

    void on_button_released(const JoystickButtonReleasedEvent &event) override {
        if (enabled)
            std::cout << "Joystick " << event.joystick_id << " button released: " << event.button << std::endl;
    }

    void on_axis_changed(const JoystickAxisChangedEvent &event) override {
        if (enabled)
            std::cout << "Joystick " << event.joystick_id << " axis changed: " << event.axis << " (" << event.value
                      << ")" << std::endl;
    }

private:
    bool enabled = false;
    bool colliders_enabled = false;
    bool _ALT = false;
};

class VelocityIndicator : public Component, public ITickable
{
private:
    float _velocity;
    int _ticks;
public:
    explicit VelocityIndicator(float velocity = 0.f)
	    : _velocity(velocity),
        _ticks(0)
    {}

    void tick(GameObject& _game_object) override
    {
	    if(_game_object.get_name() == "player_car")
	    {
            _velocity = _game_object.get_component<RigidBody>()->get_forward_velocity().length();
	    }
        if(_game_object.get_name() == "ui_velocity_indicator")
        {
            const auto text = _game_object.get_component<Text>();
            text->set_text(std::to_string(static_cast<int>(round(_velocity * 3.6f))));
        }
    }
};

class FpsIndicator : public Component, public ITickable
{
	void tick(GameObject& _game_object) override
	{
        const auto text = _game_object.get_component<Text>();
        const long long fps = Global::get_instance()->get_engine().get_fps();
        text->set_text(std::to_string(fps));
	}
};

class Car : public GameObject {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene,
        const int order_in_layer = 10, Vector2d position = Vector2d())
            : GameObject(name, tag) {
        const auto sprite =
                std::make_shared<Sprite>(std::move(sprite_path), 10);
        add_component(sprite);

        const auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
        const auto rigid_body = std::make_shared<RigidBody>(*scene, order_in_layer, BodyType::dynamic_body, position, 1.f);

        rigid_body->set_mass(1600.f);
        rigid_body->set_collider(collider);
        add_component(rigid_body);
        transform.set_scale(0.5f);
        transform.set_angle(degrees_to_radians(90.f));
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
            case LeftJoystickX:
            case LeftTouchpadX: {
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
            default:
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
            : GameObject(name, tag, transform) {
    }
};

class TargetFactory {
public:
    int counter = 0;

    std::vector<std::shared_ptr<Target>> make_targets(std::vector<Vector2d> &vectors) {
        std::vector<std::shared_ptr<Target>> res;

        for (auto &vector: vectors) {
            auto target = std::make_shared<Target>("Target" + counter, "target", Transform{vector});
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
        if (event.ai_behaviour.game_object != test)
            return;

        _target_index++;
        if (targets.size() <= _target_index) {
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
    const auto camera = std::make_shared<Camera>();
	const auto scene = std::make_shared<Scene>(camera);

    // Create game objects with component
    const auto track_outer = std::make_shared<GameObject>(
            "track_outer", "track",
            Transform{Vector2d{0.f, 0.f}});
    const auto track_inner = std::make_shared<GameObject>(
            "track_inner", "track",
            Transform{Vector2d{0.f, 0.f}});
    const auto track_grass_outer = std::make_shared<GameObject>(
        "track_grass_outer", "track", true,
        Transform{ Vector2d(0.f, 0.f) });
    const auto track_grass_inner = std::make_shared<GameObject>(
        "track_grass_inner", "track", true,
        Transform{ Vector2d(0.f, 0.f) });

    const auto track_bg = std::make_shared<GameObject>(
        "track_bg", "track",
        Transform{ Vector2d{}, Vector2d{}, 0.f, 2.f });
    Sprite sprite1{"./assets/track1.png", 1, 6.f };

    Sprite sprite2{ "./assets/track1_bg.png", 0, 6.f};

    Sprite sprite2{"./assets/track1_bg.png", Color(0, 0, 0, 255.0), false, false, 1, 0, 6.f};
    track_outer->add_component(std::make_shared<Sprite>(sprite2));
    track_bg->add_component(std::make_shared<Sprite>(sprite2));

    track_outer->add_component(std::make_shared<Sprite>(sprite1));


    const auto car = std::make_shared<Car>("player_car", "./assets/blue_car.png", Vector2d(), scene);
    car->add_component(std::make_shared<DriveInputBehaviour>(scene->get_event_manager()));
    car->add_component(std::make_shared<DriveInputControllerBehaviour>(scene->get_event_manager(), 0));
    const auto ui_velocity_indicator_behaviour = std::make_shared<VelocityIndicator>();

    const auto car = std::make_shared<Car>("player_car", "car", "./assets/blue_car.png", scene, 10, Vector2d{ 14.f, -76.f});
    const auto car_behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(car_behaviour);
    car->add_component(ui_velocity_indicator_behaviour);

    car->get_component<Sprite>()->set_color(Color(255, 255, 255, 140));
    TargetFactory tf;

    std::vector<Vector2d> vector_targets_little
            {
                    Vector2d{-60.f, -72.f},
                    Vector2d{-74.f, -53.f},
                    Vector2d{-60.f, -34.f},
                    Vector2d{-10.f, -6.f},
                    Vector2d{-13.f, 32.f},
                    Vector2d{-65.f, 38.f},
                    Vector2d{-72.f, 62.f},
                    Vector2d{-52.f, 73.f},
                    Vector2d{64.f, 73.f},
                    Vector2d{77.f, 57.f},
                    Vector2d{22.f, 37.f},
                    Vector2d{16.f, -34.f},
                    Vector2d{49.f, -39.f},
                    Vector2d{34.f, 18.f},
                    Vector2d{72.f, 20.f},
                    Vector2d{73.f, -66.f}
            };

    auto targets = tf.make_targets(vector_targets_little);

    for (auto &target: targets) {
        scene->gameobjects.push_back(target);
    }

    const auto ai_car = std::make_shared<Car>("ai_car", "./assets/blue_car.png", Vector2d{14, -76}, scene);
    ai_car->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car->add_component(ai_listener_component);
    ai_listener_component->targets = targets;

    const auto ai_car2 = std::make_shared<Car>("ai_car2", "./assets/red_car.png", Vector2d{20, -72}, scene);
    ai_car2->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component2 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car2->add_component(ai_listener_component2);
    ai_listener_component2->targets = targets;

    const auto ai_car3 = std::make_shared<Car>("ai_car3", "./assets/green_car.png", Vector2d{26, -76}, scene);
    ai_car3->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component3 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car3->add_component(ai_listener_component3);
    ai_listener_component3->targets = targets;

    const auto ai_car4 = std::make_shared<Car>("ai_car4", "./assets/pink_car.png", Vector2d{31, -72}, scene);
    ai_car4->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component4 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car4->add_component(ai_listener_component4);
    ai_listener_component4->targets = targets;

    const auto ai_car5 = std::make_shared<Car>("ai_car5", "./assets/orange_car.png", Vector2d{38, -76}, scene);
    ai_car5->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component5 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car5->add_component(ai_listener_component5);
    ai_listener_component5->targets = targets;

    const auto ai_car6 = std::make_shared<Car>("ai_car6", "./assets/yellow_car.png", Vector2d{43, -72}, scene);
    ai_car6->add_component(std::make_shared<AIBehaviour>(targets[0]));
    auto ai_listener_component6 = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
    ai_car6->add_component(ai_listener_component6);
    ai_listener_component6->targets = targets;

    const auto text = std::make_shared<GameObject>(
            "ad_board", "ad", Transform{Vector2d{-50.f, 10.f}, Vector2d{}, 0.2f, 1.f});
    text->add_component(std::make_shared<Text>("Powered by UnEngine", "./assets/Roboto/Roboto-Medium.ttf", 500, 10, Color{255,255,255,0 }, Color{0,0,0,1 }, 1));
    car->add_child(camera);


    const auto ui_velocity_indicator = std::make_shared<UIObject>("ui_velocity_indicator", "ui", 16, 32, scene->get_event_manager(), Transform{ Vector2d{-92.f, -84}, Vector2d{}, 0.f });
    const auto ui_velocity_indicator_text = std::make_shared<Text>("0", "./assets/Roboto/Roboto-Medium.ttf", 100, 1000, Color{255, 255, 255, 150}, Color{0, 0, 0, 150 }, 10);
    ui_velocity_indicator->add_component(ui_velocity_indicator_text);
    ui_velocity_indicator->add_component(ui_velocity_indicator_behaviour);

    const auto ui_fps_indicator_behaviour = std::make_shared<FpsIndicator>();

    const auto ui_fps_indicator = std::make_shared<UIObject>("ui_fps_indicator", "ui", 4, 8, scene->get_event_manager(), Transform{ Vector2d{96.f, 92}, Vector2d{}, 0.f });
    const auto ui_fps_indicator_text = std::make_shared<Text>("0",  "./assets/Roboto/Roboto-Medium.ttf", 100, 1000, Color{ 0, 255, 0, 255 }, Color{ 0, 0, 0, 150 }, 1);
    ui_fps_indicator->add_component(ui_fps_indicator_text);
    ui_fps_indicator->add_component(ui_fps_indicator_behaviour);

    scene->gameobjects.push_back(track_outer);
    scene->gameobjects.push_back(track_inner);
    scene->gameobjects.push_back(track_grass_outer);
    scene->gameobjects.push_back(track_grass_inner);
    scene->gameobjects.push_back(track_bg);
    scene->gameobjects.push_back(car);
    scene->gameobjects.push_back(ui_velocity_indicator);
    scene->gameobjects.push_back(ui_fps_indicator);
    scene->gameobjects.push_back(camera);
    scene->gameobjects.push_back(text);

    scene->gameobjects.push_back(ai_car);
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

    const auto track_grass_outer_coll = std::make_shared<ChainCollider>("./assets/track1_2x_grass_outer.xml", true, ColliderNormal::inwards);
    const auto track_grass_outer_rb = std::make_shared<RigidBody>(*scene, 2, BodyType::dynamic_body, Vector2d{ 0.f, 0.f }, 1.0f);
    track_grass_outer_rb->set_collider(track_grass_outer_coll);
    track_grass_outer->add_component(track_grass_outer_rb);

    const auto track_grass_inner_coll = std::make_shared<ChainCollider>("./assets/track1_2x_grass_inner.xml", true, ColliderNormal::outwards);
    const auto track_grass_inner_rb = std::make_shared<RigidBody>(*scene, 2, BodyType::dynamic_body, Vector2d{ 0.f, 0.f }, 1.0f);
    track_grass_inner_rb->set_collider(track_grass_inner_coll);
    track_grass_inner->add_component(track_grass_inner_rb);

    // Add listeners
    const auto key_listener_object = std::make_shared<GameObject>("KeyMouseListener", "TestTag");
    KeyMouseListenerComponent key_listener{scene->get_event_manager()};
    key_listener_object->add_component(std::make_shared<KeyMouseListenerComponent>(key_listener));
    scene->gameobjects.push_back(key_listener_object);

    const auto key_listener_object2 = std::make_shared<GameObject>("KeyMouseListener", "TestTag", true);
    KeyMouseListenerComponent key_listener2{ scene2->get_event_manager() };
    key_listener_object2->add_component(std::make_shared<KeyMouseListenerComponent>(key_listener2));
    scene2->gameobjects.push_back(key_listener_object2);

    engine_ref.load_scene(scene);
 
    Sprite sprite3{ "./assets/sample.png", Color(0, 0, 0, 255.0), false, false, 1, 1, 1.f };
    const auto test23 = std::make_shared<GameObject>("Scene2Test", "test", true);
    test23->add_component(std::make_shared<Sprite>(sprite3));
    scene2->gameobjects.push_back(test23);

    engine_ref.start();
}
