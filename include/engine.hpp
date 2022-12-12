#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <memory>
#include "scene.hpp"
#include "render/irenderer.hpp"
#include "interfaces/imultiplayer.hpp"
#include "handlers/key_handler.hpp"
#include "handlers/mouse_handler.hpp"
#include "time.hpp"

class Engine {
private:
    bool _should_quit;
    const std::unique_ptr<Time> _time;
    const std::unique_ptr<KeyHandler> _key_handler;
    const std::unique_ptr<MouseHandler> _mouse_handler;
    std::unique_ptr<IMultiplayer> _multiplayer_manager;
    std::shared_ptr<Scene> _active_scene;
    std::shared_ptr<IRenderer> _renderer;

    long long _time_after_last_frame;
    unsigned long _fps;

public:
    Engine();

    explicit Engine(std::shared_ptr<IRenderer> renderer);

    explicit Engine(const std::string& user_id, bool is_host = true);

    Engine(std::shared_ptr<IRenderer> renderer, const std::string& user_id, bool is_host = true);

    virtual ~Engine();

    void start();

    void stop();

    void load_scene(std::shared_ptr<Scene> new_scene);

    [[nodiscard]] virtual Scene &get_active_scene();

    [[nodiscard]] virtual const Scene &get_active_scene() const;

    [[nodiscard]] unsigned long get_fps() const;

    [[nodiscard]] virtual std::shared_ptr<IRenderer> get_renderer() const;

    [[nodiscard]] Time &get_time() const;
};

#endif //ENGINE_ENGINE_HPP