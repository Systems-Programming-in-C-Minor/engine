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

/**
 * @brief The engine class.
 */
class Engine {
private:
    bool _should_quit;
    const std::shared_ptr<Time> _time;
    const std::shared_ptr<KeyHandler> _key_handler;
    const std::shared_ptr<MouseHandler> _mouse_handler;
    std::shared_ptr<Scene> _active_scene;
    std::shared_ptr<IRenderer> _renderer;
    std::shared_ptr<ISoundEngine> _sound_engine;

    long long _time_after_last_frame;
    unsigned long _fps;
    int _tps;

public:
    std::shared_ptr<IMultiplayer> multiplayer_manager;

    /**
    * @brief Normal constructor.
    */
    explicit Engine();

    /**
    * @brief Constructor with given renderer and sound_engine.
    * @param renderer A shared pointer to the IRenderer the engine will use.
    * @param sound_engine A shared pointer to the ISoundEngine the engine will use.
    */
    Engine(std::shared_ptr<IRenderer> renderer, std::shared_ptr<ISoundEngine> sound_engine);

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
     * @brief The getter for the current ISoundEngine.
     * @returns A shared pointer to the current ISoundEngine.
     */
    [[nodiscard]] virtual std::shared_ptr<ISoundEngine> get_sound_engine() const;

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

    /**
     * @brief Enables multiplayer, this immediately connects to the signalling server.
     */
    void enable_multiplayer(const std::string &signalling_server);

    /**
     * @brief Disables multiplayer, this immediately disconnects from the signalling server.
     */
    void disable_multiplayer();
};

#endif //ENGINE_ENGINE_HPP