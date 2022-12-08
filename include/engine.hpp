#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <memory>
#include "scene.hpp"
#include "interfaces/isound_engine.hpp"

class Engine {
private:
    bool _should_quit;
    std::shared_ptr<Scene> _active_scene;
    std::shared_ptr<IRenderer> _renderer;
    std::shared_ptr<ISoundEngine> _sound_engine;

    long long _time_after_last_frame;
    unsigned long _fps;
public:
    Engine();
    explicit Engine(std::shared_ptr<IRenderer> renderer, std::shared_ptr<ISoundEngine> sound_engine);
    virtual ~Engine();

    void start();

    void stop();

    void load_scene(std::shared_ptr<Scene> new_scene);

    [[nodiscard]] virtual Scene &get_active_scene();
    [[nodiscard]] virtual const Scene &get_active_scene() const;

    [[nodiscard]] unsigned long get_fps() const;

    [[nodiscard]] virtual std::shared_ptr<IRenderer> get_renderer() const;
};

#endif //ENGINE_ENGINE_HPP