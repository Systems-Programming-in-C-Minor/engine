#include "components/component.hpp"

#include <utility>

Component::Component(std::string name) : _name(std::move(name)) {}

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

void Component::on_parent_set() {}

