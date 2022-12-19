#include "components/component.hpp"

Component::Component(const std::string name) : _name(name) {}

void Component::set_active(bool is_active) {
    active = is_active;
}

bool Component::get_active() const {
    return active;
}

std::string Component::get_name() const
{
    return _name;
}
