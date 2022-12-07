#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <memory>
#include "scene.hpp"
#include "render/irenderer.hpp"
#include "handlers/key_handler.hpp"

class Engine {
private:
    bool _should_quit;
    std::unique_ptr<KeyHandler> _key_handler;
    std::shared_ptr<Scene> _active_scene;
    std::unique_ptr<IRenderer> _renderer;

    long long _time_after_last_frame;
    unsigned long _fps;

public:
    Engine();
    virtual ~Engine();

    void start();

    void stop();

    void load_scene(std::shared_ptr<Scene> new_scene);

    [[nodiscard]] virtual Scene &get_active_scene();
    [[nodiscard]] virtual const Scene &get_active_scene() const;

    [[nodiscard]] unsigned long get_fps() const;
};

#endif //ENGINE_ENGINE_HPP