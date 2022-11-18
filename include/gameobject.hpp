#ifndef ENGINE_GAMEOBJECT_HPP
#define ENGINE_GAMEOBJECT_HPP

#include <string>
#include <utility>
#include <memory>
#include <list>
#include "components/component.hpp"
#include "interfaces/irenderable.hpp"

class ITickable;

#define assert_T_derived_from_component static_assert(std::is_base_of<Component, T>::value, "T not derived from Component")

/**
* @brief Any object which should be represented on screen.
*/
class GameObject {
private:
    int _id;
    static int object_counter;
protected:
    std::string name;
    std::string tag;
    bool active = true;
    int layer = 0;
    bool is_world_space = true;

    std::list<std::shared_ptr<Component>> components;

    GameObject *parent;
    std::list<std::shared_ptr<GameObject>> children;
public:
    /**
     * @brief Compare two GameObjects.
     * @param other The other object to compare this one with.
     * @return true if not equal, false otherwise.
     */
    bool operator!=(const GameObject &other) const;

    /**
     * @brief Compare two GameObjects
     * @param other The other object to compare this one with.
     * @return true if equal, false otherwise.
     */
    bool operator==(const GameObject &other) const;

    void add_child(const std::shared_ptr<GameObject> &game_object);

    void remove_child(const std::shared_ptr<GameObject> &game_object);

    std::list<std::shared_ptr<GameObject>> get_children();

    /**
     * @brief Add a Component of the specified type. Must be a valid
     *        subclass of Component. The GameObject assumes ownership of
     *        the Component.
     * @details This function places a pointer to the component in
     *          a suitable container.
     * @param component Reference to the component.
     */
    template<class T>
    void add_component(std::shared_ptr<T> component) {
        assert_T_derived_from_component;

        components.push_back(component);
    }

    /**
     * @brief Remove a the given Component.
     * @details This function removes all pointers to the component in
     *          a suitable container.
     * @param component Reference to the component.
     */
    template<class T>
    void remove_component(std::shared_ptr<T> component) {
        assert_T_derived_from_component;

        components.remove(component);
    }

    /**
     * @brief Get the first component of the specified type. Must be
     *        a valid subclass of Component.
     * @return Pointer to Component instance.
     */
    template<class T>
    [[nodiscard]] std::shared_ptr<T> get_component() const {
        assert_T_derived_from_component;

        for (const auto &component: components) {
            auto casted_component = std::dynamic_pointer_cast<T>(component);
            if (casted_component) {
                return casted_component;
            }
        }

        return nullptr;
    }

    /**
     * @brief Get the first component of the specified type from
     *        contained game objects. Must be
     *        a valid subclass of Component.
     * @return Pointer to Component instance.
     */
    template<class T>
    [[nodiscard]] std::shared_ptr<T> get_component_in_children() const {
        assert_T_derived_from_component;

        const auto component = get_component<T>();

        if (component) {
            return component;
        }

        for (const auto &child: children) {
            const auto child_component = child->get_component_in_children<T>();

            if (child_component) {
                return child_component;
            }
        }

        return nullptr;
    }

    /**
     * @brief Get all components of the specified type. Must be
     *        a valid subclass of Component.
     * @return Vector with pointers to Component instances.
     */
    template<class T>
    [[nodiscard]] std::list<std::shared_ptr<T>> get_components() const {
        assert_T_derived_from_component;

        auto output = std::list<std::shared_ptr<T>>();

        for (const auto &component: components) {
            auto casted_component = std::dynamic_pointer_cast<T>(component);
            if (casted_component) {
                output.push_back(casted_component);
            }
        }

        return output;
    }

    /**
     * @brief Get all components of the specified type from
     *        contained game objects. Must be
     *        a valid subclass of Component.
     * @return Vector with pointers to Component instances.
     */
    template<class T>
    [[nodiscard]] std::list<std::shared_ptr<T>> get_components_in_children() const {
        assert_T_derived_from_component;

        auto output = get_components<T>();

        for (const auto &child: children) {
            auto child_components = child->get_components_in_children<T>();
            output.splice(output.end(), child_components);
        }

        return output;
    }

    /**
     * @brief Activates/Deactivates the GameObject, depending on the given true or false value.
     * @param active Desired value.
     */
    void set_active(bool is_active);

    /**
     * @brief Returns whether this game object is itself active.
     * @return true if active, false if not.
     */
    [[nodiscard]] bool is_active() const;

    /**
     * @brief Returns whether this game component is active, taking its parents
     *        into consideration as well.
     * @return true if game object and all of its parents are active,
     *        false otherwise.
     */
    [[nodiscard]] bool is_active_in_world() const;

    virtual void render(IRenderer& renderer) const;

    virtual void tick();

    GameObject(std::string name, std::string tag, bool is_world_space = true);

    virtual ~GameObject();
};

#endif //ENGINE_GAMEOBJECT_HPP
