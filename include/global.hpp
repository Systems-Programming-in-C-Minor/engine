#ifndef ENGINE_GLOBAL_HPP
#define ENGINE_GLOBAL_HPP

#include <memory>
#include "engine.hpp"
#include "storage/iproperties.hpp"
#include "scene.hpp"
#include "time.hpp"
#include "input.hpp"

/**
 * @brief Global engine class.
 */
class Global {
private:
    /**
     * @brief Constructor.
     * @param engine The engine reference of the Global object.
     * @param properties The properties reference of the Global object.
     */
    Global(std::unique_ptr<Engine> engine, std::unique_ptr<IProperties> properties);

    static Global *_instance;

    std::unique_ptr<Engine> _engine;
    std::unique_ptr<IProperties> _properties;
public:
    /**
     * @brief Static method which returns a pointer to the Global instance.
     * @return A pointer to the Global instance.
     */
    static Global *get_instance();

    /**
     * @brief Setter method for the engine.
     * @param engine A unique pointer to the engine which will be set.
     */
    void set_engine(std::unique_ptr<Engine> engine);

    /**
     * @brief Getter method for the engine.
     * @return A reference to the engine object.
     */
    Engine& get_engine();

    /**
     * @brief Getter method for the engine.
     * @return A reference to the engine object.
     */
    [[nodiscard]] const Engine& get_engine() const;

    /**
     * @brief Setter method for the properties.
     * @param properties A unique pointer to the IProperties which will be set.
     */
    void set_properties(std::unique_ptr<IProperties> properties);

    /**
     * @brief Getter method for the engine.
     * @return A reference to the IProperties object.
     */
    IProperties& get_properties();

    /**
     * @brief Getter method for the engine.
     * @return A reference to the IProperties object.
     */
    [[nodiscard]] const IProperties& get_properties() const;

    /**
     * @brief Getter method for the active scene.
     * @return A reference to the Scene object.
     */
    Scene& get_active_scene();

    /**
     * @brief Getter method for the active scene.
     * @return A reference to the Scene object.
     */
    [[nodiscard]] const Scene& get_active_scene() const;

    /**
     * @brief Getter method for the current delta time.
     * @return A float value of the current delta time.
     */
    float get_delta_time();

    /**
     * @brief Method which notifies the event manager.
     * @param event The event which will be used for notifying.
     */
    void notify_event_manager(const IEvent& event);

    /**
     * @brief Method which sets one Global instance to another.
     * @param & The Global object which will be set.
     */
    void operator=(const Global &) = delete;

    Input input;
};

#endif //ENGINE_GLOBAL_HPP
