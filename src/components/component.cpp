#include "components/component.hpp"

void Component::setActive(bool isActive) {
    active = isActive;
}

bool Component::getActive() const {
    return active;
}

