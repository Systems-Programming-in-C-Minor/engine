#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <memory>
#include "scene.hpp"
#include "render/irenderer.hpp"
#include "interfaces/imultiplayer.hpp"
#include "handlers/key_handler.hpp"
#include "handlers/mouse_handler.hpp"
#include "time.hpp"

/**
 * @brief The engine class.
 */
class Engine {
private:
    bool _should_quit;
    const std::shared_ptr<Time> _time;
    const std::shared_ptr<KeyHandler> _key_handler;
    const std::shared_ptr<MouseHandler> _mouse_handler;
    std::shared_ptr<IMultiplayer> _multiplayer_manager;
    std::shared_ptr<Scene> _active_scene;
    std::shared_ptr<IRenderer> _renderer;

    long long _time_after_last_frame;
    unsigned long _fps;
    int _tps;

public:
    /**
    * @brief Constructor.
    */
    Engine();

    /**
    * @brief Explicit constructor.
    * @param renderer A shared pointer to the IRenderer the engine will use.
    */
    explicit Engine(std::shared_ptr<IRenderer> renderer);

    /**
    * @brief Explicit constructor.
    * @param user_id The user_id the engine class will refer to.
    * @param is_host The boolean value whether the engine is a host.
    */
    explicit Engine(const std::string &user_id, bool is_host = true);

    /**
    * @brief Constructor.
    * @param renderer A shared pointer to the IRenderer the engine will use.
    * @param user_id The user_id the engine class will refer to.
    * @param is_host The boolean value whether the engine is a host.
    */
    Engine(std::shared_ptr<IRenderer> renderer, const std::string &user_id, bool is_host = true);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Engine();

    /**
     * @brief The method which will start the engine.
     */
    void start();

    /**
     * @brief The method which will stop the engine.
     */
    void stop();

    /**
     * @brief The method which will load a scene.
     * @param new_scene The new scene which will be loaded.
     */
    void load_scene(std::shared_ptr<Scene> new_scene);

    /**
     * @brief The getter for the active scene.
     * @returns The current active Scene.
     */
    [[nodiscard]] virtual Scene &get_active_scene();

    /**
     * @brief The const getter for the active scene.
     * @returns The current active Scene as a const value.
     */
    [[nodiscard]] virtual const Scene &get_active_scene() const;

    /**
     * @brief The getter for the current fps.
     * @returns An unsigned long value for the current fps.
     */
    [[nodiscard]] unsigned long get_fps() const;

    /**
     * @brief The getter for the current IRenderer.
     * @returns A shared pointer to the current IRenderer.
     */
    [[nodiscard]] virtual std::shared_ptr<IRenderer> get_renderer() const;

    /**
     * @brief The setter method for the current ticks per seconds.
     * @param tps The new ticks per seconds, default at 60.
     */
    void set_ticks_per_second(int tps = 60);

    /**
     * @brief The getter for the current ticks per seconds.
     * @returns An integer value of the tps.
     */
    [[nodiscard]] int get_ticks_per_second() const;

    /**
     * @brief The getter for the current number of controllers.
     * @returns An unsigned long value of the number of known controllers.
     */
    [[nodiscard]] unsigned long get_number_of_controllers() const;

    /**
     * @brief The getter for the current Time object of the engine.
     * @returns A Time object of the current time of the engine.
     */
    [[nodiscard]] Time &get_time() const;
};

#endif //ENGINE_ENGINE_HPP