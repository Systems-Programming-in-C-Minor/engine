#include "GameObject.hpp"

int GameObject::objectCounter = 0;

GameObject::GameObject(std::string name, std::string tag) : name(std::move(name)),
                                                            tag(std::move(tag)),
                                                            parent(nullptr),
                                                            _id(objectCounter++) {}

void GameObject::addChild(const std::shared_ptr<GameObject> &gameObject) {
    children.push_back(gameObject);
    gameObject->parent = this;
}

void GameObject::removeChild(const std::shared_ptr<GameObject> &gameObject) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == gameObject) {
            it->get()->parent = nullptr;
            children.erase(it);
            return;
        }
    }
}

std::list<std::shared_ptr<GameObject>> GameObject::getChildren() {
    return children;
}

bool GameObject::isActive() const {
    return active;
}

void GameObject::setActive(bool isActive) {
    active = isActive;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

bool GameObject::isActiveInWorld() const {
    return active && (parent == nullptr || parent->isActiveInWorld());
}

#pragma clang diagnostic pop

bool GameObject::operator!=(const GameObject &other) const {
    return !(*this == other);
}

bool GameObject::operator==(const GameObject &other) const {
    return _id == other._id;
}

GameObject::~GameObject() = default;
