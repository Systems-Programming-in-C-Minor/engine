#include "components/component.hpp"

void Component::set_active(bool is_active) {
    active = is_active;
}

bool Component::get_active() const {
    return active;
}

