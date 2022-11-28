#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <memory>
#include "scene.hpp"
#include "render/irenderer.hpp"


class Engine {
private:
    bool _should_quit;
    std::shared_ptr<Scene> _active_scene;
    std::unique_ptr<IRenderer> _renderer;

    long _time_after_last_frame;
    unsigned long _fps;

    static void listen_keyboard_state();
public:
    void start();

    void stop();

    void load_scene(std::shared_ptr<Scene> new_scene);

    [[nodiscard]] Scene &get_active_scene() const;

    [[nodiscard]] unsigned long get_fps() const;
};

#endif //ENGINE_ENGINE_HPP