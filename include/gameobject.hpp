#ifndef ENGINE_GAMEOBJECT_HPP
#define ENGINE_GAMEOBJECT_HPP

#include <string>
#include <utility>
#include <memory>
#include <list>
#include "components/component.hpp"
#include "interfaces/irenderable.hpp"
#include "transform.hpp"

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

    std::list<std::shared_ptr<Component>> components;

    GameObject *parent;
    std::list<std::shared_ptr<GameObject>> children;
public:
    Transform transform;
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

    /**
     * @brief Add a child to the current game object.
     * @param game_object The game object which will be added as a child.
     */
    void add_child(const std::shared_ptr<GameObject> &game_object);

    /**
     * @brief Remove a child from the current game object.
     * @param game_object The game object which will be removed from the children.
     */
    void remove_child(const std::shared_ptr<GameObject> &game_object);

    /**
     * @brief Getter method for the children of the current game object.
     * @return A list of shared pointers, containing all children as game objects.
     */
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
        std::dynamic_pointer_cast<Component>(component)->game_object = this;
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
        std::dynamic_pointer_cast<Component>(component)->game_object = nullptr;
    }

    /**
     * @brief Remove a the given Component.
     * @details This function removes all pointers to the component in
     *          a suitable container.
     * @param component Reference to the component.
     */
    template<class T>
    void remove_component() {
        assert_T_derived_from_component;

        auto component = get_component<T>();

        if (!component) return;

        components.remove(component);
        std::dynamic_pointer_cast<Component>(component)->game_object = nullptr;
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
     * @brief Returns the name of the game object.
     * @return a std::string containing the name of the game object.
     */
    std::string get_name() const;

    /**
     * @brief Returns the tag of the game object.
     * @return a std::string containing the tag of the game object.
     */
    std::string get_tag() const;

    /**
     * @brief Returns whether this game component is active, taking its parents
     *        into consideration as well.
     * @return true if game object and all of its parents are active,
     *        false otherwise.
     */
    [[nodiscard]] bool is_active_in_world() const;

    /**
     * @brief Render the game object.
     *        Override for implementing the desired behaviour.
     */
    virtual void render() const;

    /**
     * @brief Method will be ran every tick.
     *        Override for implementing the desired behaviour.
     */
    virtual void tick();

    /**
     * @brief Constructor
     * @param name The name of the game object.
     * @param tag The tag of the game object.
     * @param transform The initial transform of the game object.
     */
    GameObject(std::string name, std::string tag, Transform transform = Transform{Vector2d{}});

    /**
     * @brief Virtual destructor.
     */
    virtual ~GameObject();
};

#endif //ENGINE_GAMEOBJECT_HPP
