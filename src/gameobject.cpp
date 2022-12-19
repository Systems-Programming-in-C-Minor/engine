#include "gameobject.hpp"
#include "interfaces/itickable.hpp"

int GameObject::object_counter = 0;

GameObject::GameObject(std::string name, std::string tag, bool is_world_space, Transform _transform) :
	_id(object_counter++),
	name(std::move(name)),
	tag(std::move(tag)),
    is_world_space(is_world_space),
	parent(nullptr),
    transform(_transform){
    transform._game_object = this;
}

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

std::string GameObject::get_name() const {
    return name;
}

std::string GameObject::get_tag() const {
    return tag;
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

void GameObject::render() const {
    auto renderable_components = std::list<std::shared_ptr<IRenderable>>();

    for (const auto &component: get_components_in_children<Component>()) {
        const auto renderable = std::dynamic_pointer_cast<IRenderable>(component);
        if (renderable) {
            renderable->render(is_world_space);

        }
    }
}

void GameObject::tick() {
    if (parent) {
        auto child_pos = parent->transform.get_position() + transform.get_local_position();
        transform.set_position(child_pos);

        auto child_angle = parent->transform.get_angle() + transform.get_local_angle();
        transform.set_angle(child_angle);
    }

    for (const auto &component: get_components_in_children<Component>()) {
        auto tickable = std::dynamic_pointer_cast<ITickable>(component);
        if (tickable) {
            tickable->tick(*this);
        }
    }
}

GameObject::~GameObject() = default;
