#include "gameobject.hpp"

int GameObject::object_counter = 0;

GameObject::GameObject(std::string name, std::string tag) : name(std::move(name)),
                                                            tag(std::move(tag)),
                                                            parent(nullptr),
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

GameObject::~GameObject() = default;
