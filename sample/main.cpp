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
#include "components/audiosource.hpp"
#include "listeners/joystick_listener.hpp"
#include "listeners/ai_listener.hpp"
#include <cstring>
#include "race/objects/car.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/behaviours/drive_input_controller_behaviour.hpp"
#include "race/objects/networkables/networkable_car.hpp"

const auto camera = std::make_shared<Camera>(20.0f);
const auto camera2 = std::make_shared<Camera>(6.0f);
const auto scene = std::make_shared<Scene>(camera);
const auto scene2 = std::make_shared<Scene>(camera2);

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
        if (event.key == NUM_5 && _ALT)
            Global::get_instance()->get_engine().load_scene(scene2);
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

class VelocityIndicator : public Component, public ITickable {
private:
    float _velocity;
    int _ticks;
public:
    explicit VelocityIndicator(float velocity = 0.f)
            : _velocity(velocity),
              _ticks(0) {}

    void tick(GameObject &_game_object) override {
        if (_game_object.get_tag() == "car") {
            _velocity = _game_object.get_component<RigidBody>()->get_forward_velocity().length();
        }
        if (_game_object.get_name() == "ui_velocity_indicator") {
            const auto text = _game_object.get_component<Text>();
            text->set_text(std::to_string(static_cast<int>(round(_velocity * 3.6f))));
        }
    }
};

class DebugScreenToWorld : public Component, public MouseListener {
public:
    explicit DebugScreenToWorld(EventManager &event_manager)
            : MouseListener(event_manager) {}

    void on_mouse_pressed(const MousePressedEvent &event) override {
        const auto click_pos = Vector2d{
                static_cast<float>(event.x),
                static_cast<float>(event.y)
        };
        const auto result_pos = Global::get_instance()->get_engine().get_renderer()->screen_to_world_space(click_pos);
        std::cout << result_pos << "\n";
    }
};

class FpsIndicator : public Component, public ITickable {
    void tick(GameObject &_game_object) override {
        const auto text = _game_object.get_component<Text>();
        const unsigned long fps = Global::get_instance()->get_engine().get_fps();
        text->set_text(std::to_string(fps));
    }
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
            auto target = std::make_shared<Target>("Target" + std::to_string(counter), "target", Transform{vector});
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

    int target_index = 0;

    void on_target_reached(const AITargetReachedEvent &event) override {
        auto ai_behaviour = game_object->get_component<AIBehaviour>();

        if (ai_behaviour == nullptr)
            return;

        if (event.ai_behaviour.game_object != ai_behaviour->game_object)
            return;

        target_index++;
        if (targets.size() <= target_index) {
            target_index = 0;
        }
        event.ai_behaviour.set_target(targets[target_index]);
    };
};

int main() {

    // Setup engine
    const auto global = Global::get_instance();
    auto engine = std::make_unique<Engine>();
    global->set_engine(std::move(engine));
    global->set_properties(std::make_unique<JsonProperties>("settings.json"));
    Engine &engine_ref = global->get_engine();

    // Setup music
    const auto background_music = std::make_shared<AudioSource>("./assets/audio/background1.mp3", false, false, 0.1,
                                                                "background");
    const auto acceleration_sound = std::make_shared<AudioSource>("./assets/audio/engine-driving.mp3", false, false,
                                                                  0.1, "acceleration");
    const auto engine_idle = std::make_shared<AudioSource>("./assets/audio/engine-idle.mp3", false, true, 0.2,
                                                           "engine_idle");
    const auto car_drift = std::make_shared<AudioSource>("./assets/audio/tire-screech-drift.mp3", false, false, 0.2,
                                                         "car_drift");
    const auto car_drive_off = std::make_shared<AudioSource>("./assets/audio/tire-screech-drive-off.mp3", false, false,
                                                             0.2, "car_drive_off");
    const auto car_crash = std::make_shared<AudioSource>("./assets/audio/car-crash.mp3", false, false, 1, "car_crash");
    background_music->play(true);
    engine_idle->play(true);

    // Create game objects with component
    const auto track_outer = std::make_shared<GameObject>(
            "track_outer", "track",
            Transform{Vector2d{0.f, 0.f}});
    const auto track_inner = std::make_shared<GameObject>(
            "track_inner", "track",
            Transform{Vector2d{0.f, 0.f}});
    const auto track_grass_outer = std::make_shared<GameObject>(
            "track_grass_outer", "track");
    const auto track_grass_inner = std::make_shared<GameObject>(
            "track_grass_inner", "track");

    const auto track_bg = std::make_shared<GameObject>(
            "track_bg", "track",
            Transform{Vector2d{}, Vector2d{}, 0.f, 2.f});
    Sprite sprite1{"./assets/track1.png", 1, 12.f};

    Sprite sprite2{"./assets/track1_bg.png", 0, 6.f};

    track_outer->add_component(std::make_shared<Sprite>(sprite2));
    track_bg->add_component(std::make_shared<Sprite>(sprite2));

    track_outer->add_component(std::make_shared<Sprite>(sprite1));

    const auto ui_velocity_indicator_behaviour = std::make_shared<VelocityIndicator>();

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

    const auto car_sprites = std::vector<std::string>{
            "blue_car.png",
            "red_car.png",
            "green_car.png",
            "pink_car.png",
            "orange_car.png",
            "yellow_car.png",
    };

    engine_ref.enable_multiplayer("signaling.maik.sh:10000");

    auto cars = std::vector<std::shared_ptr<NetworkableCar>>();

    for (int i = 0; i < car_sprites.size(); i++) {
        const auto &sprite = car_sprites[i];
        const auto ai_car = std::make_shared<Car>(sprite.substr(0, sprite.find('.')), "./assets/" + sprite,
                                                  Vector2d{static_cast<float>(14 + i * 5), static_cast<float>(-76 + i)},
                                                  scene);

        const auto networkable_car = std::make_shared<NetworkableCar>(ai_car, false, true);

        engine_ref.multiplayer_manager->register_networkable(networkable_car);
        cars.push_back(networkable_car);
    }

    scene->get_event_manager().register_listener(HostMultiplayer, [&cars, &targets](const IEvent &) {
        for (const auto &car: cars) {
            car->car->add_component(std::make_shared<AIBehaviour>(targets[0]));
            auto ai_listener_component = std::make_shared<AITargetListenerComponent>(scene->get_event_manager());
            car->car->add_component(ai_listener_component);
            ai_listener_component->targets = targets;

            car->transmit = true;
            car->receive = false;
        }
    });


    scene->get_event_manager().register_listener(UserJoinedMultiplayer, [&cars, &engine_ref](const IEvent &event) {
        const auto e = dynamic_cast<const UserJoinedMultiplayerEvent &>(event);
        const auto id = e.user_id;

        if (id >= cars.size()) return;
        if (!engine_ref.multiplayer_manager->is_host) return;

        auto car = cars[id]->car;
        car->remove_component<AIBehaviour>();
        car->get_component<AITargetListenerComponent>()->target_index = 0;

        cars[id]->transmit = false;
        cars[id]->receive = true;
    });

    scene->get_event_manager().register_listener(AllocationMultiplayer, [&cars, &ui_velocity_indicator_behaviour](const IEvent &event) {
        const auto e = dynamic_cast<const AllocationMultiplayerEvent &>(event);
        const auto id = e.user_id;

        if (id >= cars.size()) return;

        auto car = cars[id]->car;
        car->remove_component<AIBehaviour>();
        car->add_component(std::make_shared<DriveInputBehaviour>(scene->get_event_manager()));
        car->add_component(std::make_shared<DriveInputControllerBehaviour>(scene->get_event_manager(), 0));

        car->add_child(camera);
        car->add_component(ui_velocity_indicator_behaviour);
        car->get_component<Sprite>()->set_color(Color(255, 255, 255, 140));

        cars[id]->transmit = true;
        cars[id]->receive = false;
    });

    scene->get_event_manager().register_listener(UserLeftMultiplayer, [&cars, &engine_ref](const IEvent &event) {
        const auto e = dynamic_cast<const UserLeftMultiplayerEvent &>(event);
        const auto id = e.user_id;

        if (id >= cars.size()) return;
        if (!engine_ref.multiplayer_manager->is_host) return;

        auto car = cars[id]->car;

        const auto air_target_listener = car->get_component<AITargetListenerComponent>();

        car->add_component(std::make_shared<AIBehaviour>(
                air_target_listener->targets[air_target_listener->target_index]
        ));

        cars[id]->transmit = true;
        cars[id]->receive = false;
    });

    scene->get_event_manager().register_listener(UsersMultiplayer, [&cars, &engine_ref](const IEvent &event) {
        const auto e = dynamic_cast<const UsersMultiplayerEvent &>(event);
        const auto ids = e.user_ids;

        if (!engine_ref.multiplayer_manager->is_host) return;

        auto ids_str = std::string();

        for (const auto &id: ids) {
            if (id >= cars.size()) continue;
            cars[id]->car->remove_component<AIBehaviour>();
        }
    });

    const auto text = std::make_shared<GameObject>(
            "ad_board", "ad", Transform{Vector2d{-50.f, 10.f}, Vector2d{}, 0.2f, 1.f});

    text->add_component(std::make_shared<Text>("Powered by UnEngine", "./assets/Roboto/Roboto-Medium.ttf", 500, 10,
                                               Color{255, 255, 255, 0}, Color{0, 0, 0, 1}, 1));


    const auto ui_velocity_indicator = std::make_shared<UIObject>("ui_velocity_indicator", "ui", 16, 32,
                                                                  scene->get_event_manager(),
                                                                  Transform{Vector2d{-92.f, -84}, Vector2d{}, 0.f});
    const auto ui_velocity_indicator_text = std::make_shared<Text>("0", "./assets/Roboto/Roboto-Medium.ttf", 100, 1000,
                                                                   Color{255, 255, 255, 150}, Color{0, 0, 0, 150}, 10);
    ui_velocity_indicator->add_component(ui_velocity_indicator_text);
    ui_velocity_indicator->add_component(ui_velocity_indicator_behaviour);

    const auto ui_fps_indicator_behaviour = std::make_shared<FpsIndicator>();
    const auto ui_fps_indicator = std::make_shared<UIObject>("ui_fps_indicator", "ui", 4, 8, scene->get_event_manager(),
                                                             Transform{Vector2d{96.f, 92}, Vector2d{}, 0.f});
    const auto ui_fps_indicator_text = std::make_shared<Text>("0", "./assets/Roboto/Roboto-Medium.ttf", 100, 1000,
                                                              Color{0, 255, 0, 255}, Color{0, 0, 0, 150}, 1);
    ui_fps_indicator->add_component(ui_fps_indicator_text);
    ui_fps_indicator->add_component(ui_fps_indicator_behaviour);
    // For debug purposes
    ui_fps_indicator->add_component(std::make_shared<DebugScreenToWorld>(scene->get_event_manager()));

    scene->gameobjects.push_back(track_outer);
    scene->gameobjects.push_back(track_inner);
    scene->gameobjects.push_back(track_grass_outer);
    scene->gameobjects.push_back(track_grass_inner);
    scene->gameobjects.push_back(track_bg);
    scene->gameobjects.push_back(ui_velocity_indicator);
    scene->gameobjects.push_back(ui_fps_indicator);
    scene->gameobjects.push_back(text);

    for (const auto &car: cars) {
        scene->gameobjects.push_back(car->car);
    }

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

    const auto track_grass_outer_coll = std::make_shared<ChainCollider>("./assets/track1_2x_grass_outer.xml", true,
                                                                        ColliderNormal::inwards);
    const auto track_grass_outer_rb = std::make_shared<RigidBody>(*scene, 2, BodyType::dynamic_body, Vector2d{0.f, 0.f},
                                                                  1.0f);
    track_grass_outer_rb->set_collider(track_grass_outer_coll);
    track_grass_outer->add_component(track_grass_outer_rb);

    const auto track_grass_inner_coll = std::make_shared<ChainCollider>("./assets/track1_2x_grass_inner.xml", true,
                                                                        ColliderNormal::outwards);
    const auto track_grass_inner_rb = std::make_shared<RigidBody>(*scene, 2, BodyType::dynamic_body, Vector2d{0.f, 0.f},
                                                                  1.0f);
    track_grass_inner_rb->set_collider(track_grass_inner_coll);
    track_grass_inner->add_component(track_grass_inner_rb);

    // Add listeners
    const auto key_listener_object = std::make_shared<GameObject>("KeyMouseListener", "TestTag");
    KeyMouseListenerComponent key_listener{scene->get_event_manager()};
    key_listener_object->add_component(std::make_shared<KeyMouseListenerComponent>(key_listener));
    scene->gameobjects.push_back(key_listener_object);

    const auto key_listener_object2 = std::make_shared<GameObject>("KeyMouseListener", "TestTag");
    KeyMouseListenerComponent key_listener2{scene2->get_event_manager()};
    key_listener_object2->add_component(std::make_shared<KeyMouseListenerComponent>(key_listener2));
    scene2->gameobjects.push_back(key_listener_object2);

    engine_ref.load_scene(scene);

    Sprite sprite3{"./assets/sample.png", 1};
    const auto test23 = std::make_shared<GameObject>("Scene2Test", "test");
    test23->add_component(std::make_shared<Sprite>(sprite3));
    scene2->gameobjects.push_back(test23);

    engine_ref.start();
}
