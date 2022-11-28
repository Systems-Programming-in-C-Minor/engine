#ifndef ENGINE_GLOBAL_HPP
#define ENGINE_GLOBAL_HPP

#include <memory>
#include "engine.hpp"
#include "storage/iproperties.hpp"
#include "scene.hpp"
#include "time.hpp"

class Global {
private:
    Global(std::unique_ptr<Engine> engine, std::unique_ptr<IProperties> properties);

    static Global *_instance;

    std::unique_ptr<Engine> _engine;
    std::unique_ptr<IProperties> _properties;

public:
    static Global *get_instance();

    Global(Global &other) = delete;

    void set_engine(std::unique_ptr<Engine> engine);
    Engine& get_engine();
    [[nodiscard]] const Engine& get_engine() const;

    void set_properties(std::unique_ptr<IProperties> properties);
    IProperties& get_properties();
    [[nodiscard]] const IProperties& get_properties() const;

    Scene& get_active_scene();
    [[nodiscard]] const Scene& get_active_scene() const;

    void operator=(const Global &) = delete;
    Time time;
};

#endif //ENGINE_GLOBAL_HPP
