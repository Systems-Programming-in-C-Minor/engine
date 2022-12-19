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
#include "race/behaviours/car_behaviour.hpp"
#include "utils/trigonometry.hpp"
#include "utils/xmlreader.hpp"
#include "uiobject.hpp"
#include "components/text.hpp"
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
            const auto text = _game_object.get_component<TextNew>();
            text->set_text(std::to_string(static_cast<int>(round(_velocity * 3.6f))));
        }
    }
};

class FpsIndicator : public Component, public ITickable
{
	void tick(GameObject& _game_object) override
	{
        const auto text = _game_object.get_component<TextNew>();
        const long long fps = Global::get_instance()->get_engine().get_fps();
        text->set_text(std::to_string(fps));
	}
};

class Car : public GameObject {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene,
        const int order_in_layer = 10)
            : GameObject(name, tag) {
        const auto sprite =
                std::make_shared<Sprite>(std::move(sprite_path), 10);
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
    const auto camera = std::make_shared<Camera>();
	const auto scene = std::make_shared<Scene>(camera);

    // Create game objects with component
    const auto track_outer = std::make_shared<GameObject>(
            "track_outer", "track", true,
            Transform{Vector2d{0.f, 0.f}});
    const auto track_inner = std::make_shared<GameObject>(
            "track_inner", "track", true,
            Transform{Vector2d{0.f, 0.f}});

    Sprite sprite1{"./assets/track1.png", 1, 6.f };

    track_outer->add_component(std::make_shared<Sprite>(sprite1));

    const auto ui_velocity_indicator_behaviour = std::make_shared<VelocityIndicator>();

    const auto car = std::make_shared<Car>("player_car", "car", "./assets/blue_car.png", scene);
    const auto car_behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(car_behaviour);
    car->add_component(ui_velocity_indicator_behaviour);

    const auto text = std::make_shared<GameObject>(
            "text", "text", true, Transform{Vector2d{}, Vector2d{}, 2.f, 4.f});
    text->add_component(std::make_shared<TextNew>("Test", "./assets/Roboto/Roboto-Medium.ttf", 70, 10));
    car->add_child(camera);


    const auto ui_velocity_indicator = std::make_shared<UIObject>("ui_velocity_indicator", "ui", true, 16, 32, scene->get_event_manager(), Transform{ Vector2d{-92.f, -84}, Vector2d{}, 0.f });
    const auto ui_velocity_indicator_text = std::make_shared<TextNew>("0", "./assets/Roboto/Roboto-Medium.ttf", 100, 1000, Color{255, 255, 255, 150}, Color{0, 0, 0, 150 }, 10);
    ui_velocity_indicator->add_component(ui_velocity_indicator_text);
    ui_velocity_indicator->add_component(ui_velocity_indicator_behaviour);

    const auto ui_fps_indicator_behaviour = std::make_shared<FpsIndicator>();

    const auto ui_fps_indicator = std::make_shared<UIObject>("ui_fps_indicator", "ui", true, 4, 8, scene->get_event_manager(), Transform{ Vector2d{96.f, 92}, Vector2d{}, 0.f });
    const auto ui_fps_indicator_text = std::make_shared<TextNew>("0",  "./assets/Roboto/Roboto-Medium.ttf", 100, 1000, Color{ 0, 255, 0, 255 }, Color{ 0, 0, 0, 150 }, 1);
    ui_fps_indicator->add_component(ui_fps_indicator_text);
    ui_fps_indicator->add_component(ui_fps_indicator_behaviour);

    scene->gameobjects.push_back(track_outer);
    scene->gameobjects.push_back(track_inner);
    scene->gameobjects.push_back(car);
    scene->gameobjects.push_back(ui_velocity_indicator);
    scene->gameobjects.push_back(ui_fps_indicator);
    scene->gameobjects.push_back(camera);
    scene->gameobjects.push_back(text);

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
