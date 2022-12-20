#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <memory>
#include "scene.hpp"
#include "render/irenderer.hpp"
#include "interfaces/imultiplayer.hpp"
#include "interfaces/isound_engine.hpp"
#include "handlers/key_handler.hpp"
#include "handlers/mouse_handler.hpp"
#include "time.hpp"

class Engine {
private:
    bool _should_quit;
    const std::shared_ptr<Time> _time;
    const std::shared_ptr<KeyHandler> _key_handler;
    const std::shared_ptr<MouseHandler> _mouse_handler;
    std::shared_ptr<IMultiplayer> _multiplayer_manager;
    std::shared_ptr<Scene> _active_scene;
    std::shared_ptr<IRenderer> _renderer;
    std::shared_ptr<ISoundEngine> _sound_engine;

    long long _time_after_last_frame;
    unsigned long _fps;
    int _tps;

public:
    Engine();

    explicit Engine(std::shared_ptr<IRenderer> renderer, std::shared_ptr<ISoundEngine> sound_engine);

    explicit Engine(const std::string &user_id, bool is_host = true);

    Engine(std::shared_ptr<IRenderer> renderer, std::shared_ptr<ISoundEngine> sound_engine, const std::string& user_id, bool is_host = true);

    virtual ~Engine();

    void start();

    void stop();

    void load_scene(std::shared_ptr<Scene> new_scene);

    [[nodiscard]] virtual Scene &get_active_scene();

    [[nodiscard]] virtual const Scene &get_active_scene() const;

    [[nodiscard]] unsigned long get_fps() const;

    void set_ticks_per_second(int tps = 60);

    [[nodiscard]] int get_ticks_per_second() const;

	[[nodiscard]] virtual std::shared_ptr<IRenderer> get_renderer() const;

    [[nodiscard]] virtual std::shared_ptr<ISoundEngine> get_sound_engine() const;

    [[nodiscard]] unsigned long get_number_of_controllers() const;

    [[nodiscard]] Time &get_time() const;
};

#endif //ENGINE_ENGINE_HPP