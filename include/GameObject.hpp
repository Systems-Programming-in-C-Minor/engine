#pragma once

#include <string>
#include <utility>
#include <memory>
#include <list>
#include "components/Component.hpp"

#define assertTDerivedFromComponent static_assert(std::is_base_of<Component, T>::value, "T not derived from Component")

/**
     * @brief Any object which should be represented on screen.
     */
class GameObject {
private:
    int _id;
    static int objectCounter;
protected:
    std::string name;
    std::string tag;
    bool active = true;
    int layer = 0;

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

    void addChild(const std::shared_ptr<GameObject> &gameObject);

    void removeChild(const std::shared_ptr<GameObject> &gameObject);

    std::list<std::shared_ptr<GameObject>> getChildren();

    /**
     * @brief Add a Component of the specified type. Must be a valid
     *        subclass of Component. The GameObject assumes ownership of
     *        the Component.
     * @details This function places a pointer to the component in
     *          a suitable container.
     * @param component Reference to the component.
     */
    template<class T>
    void addComponent(std::shared_ptr<T> component) {
        assertTDerivedFromComponent;

        components.push_back(component);
    }

    /**
     * @brief Get the first component of the specified type. Must be
     *        a valid subclass of Component.
     * @return Pointer to Component instance.
     */
    template<class T>
    [[nodiscard]] std::shared_ptr<T> getComponent() const {
        assertTDerivedFromComponent;

        for (const auto &component: components) {
            auto castedComponent = std::dynamic_pointer_cast<T>(component);
            if (castedComponent) {
                return castedComponent;
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
    [[nodiscard]] std::shared_ptr<T> getComponentInChildren() const {
        assertTDerivedFromComponent;

        const auto component = getComponent<T>();

        if (component) {
            return component;
        }

        for (const auto &child: children) {
            const auto childComponent = child->getComponentInChildren<T>();

            if (childComponent) {
                return childComponent;
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
    [[nodiscard]] std::list<std::shared_ptr<T>> getComponents() const {
        assertTDerivedFromComponent;

        auto output = std::list<std::shared_ptr<T>>();

        for (const auto &component: components) {
            auto castedComponent = std::dynamic_pointer_cast<T>(component);
            if (castedComponent) {
                output.push_back(castedComponent);
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
    [[nodiscard]] std::list<std::shared_ptr<T>> getComponentsInChildren() const {
        assertTDerivedFromComponent;

        auto output = getComponents<T>();

        for (const auto &child: children) {
            auto childComponents = child->getComponentsInChildren<T>();
            output.splice(output.end(), childComponents);
        }

        return output;
    }

    /**
     * @brief Activates/Deactivates the GameObject, depending on the given true or false value.
     * @param active Desired value.
     */
    void setActive(bool isActive);

    /**
     * @brief Returns whether this game object is itself active.
     * @return true if active, false if not.
     */
    [[nodiscard]] bool isActive() const;

    /**
     * @brief Returns whether this game component is active, taking its parents
     *        into consideration as well.
     * @return true if game object and all of its parents are active,
     *        false otherwise.
     */
    [[nodiscard]] bool isActiveInWorld() const;

    GameObject(std::string name, std::string tag);

    virtual ~GameObject();
};