#include "gameobject.hpp"
#include "interfaces/itickable.hpp"

int GameObject::object_counter = 0;

GameObject::GameObject(std::string name, std::string tag, bool is_world_space) : name(std::move(name)),
                                                                                tag(std::move(tag)),
                                                                                parent(nullptr),
                                                                                is_world_space(is_world_space),
                                                                                _id(object_counter++) {}

void GameObject::add_child(const std::shared_ptr<GameObject> &game_object) {
    children.push_back(game_object);
    game_object->parent = this;
}

void GameObject::remove_child(const std::shared_ptr<GameObject> &game_object) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == game_object) {
            it->get()->parent = nullptr;
            children.erase(it);
            return;
        }
    }
}

std::list<std::shared_ptr<GameObject>> GameObject::get_children() {
    return children;
}

bool GameObject::is_active() const {
    return active;
}

void GameObject::set_active(bool is_active) {
    active = is_active;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

bool GameObject::is_active_in_world() const {
    return active && (parent == nullptr || parent->is_active_in_world());
}

#pragma clang diagnostic pop

bool GameObject::operator!=(const GameObject &other) const {
    return !(*this == other);
}

bool GameObject::operator==(const GameObject &other) const {
    return _id == other._id;
}

void GameObject::render(IRenderer &renderer) const {
    auto renderable_components = std::list<std::shared_ptr<IRenderable>>();

    for (const auto &component: get_components_in_children<Component>()) {
        const auto renderable = std::dynamic_pointer_cast<IRenderable>(component);
        if (renderable) {
            renderable->render(renderer, is_world_space);

        }
    }
}

void GameObject::tick() {
    for (const auto &component: get_components_in_children<Component>()) {
        auto tickable = std::dynamic_pointer_cast<ITickable>(component);
        if (tickable) {
            tickable->tick(*this);
        }
    }
}

GameObject::~GameObject() = default;
