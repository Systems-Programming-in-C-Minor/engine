#include "components/Component.hpp"

void Component::setActive(bool isActive) {
    active = isActive;
}

bool Component::getActive() const {
    return active;
}

