#include "collision_handler.hpp"
#include "global.hpp"
#include "events.hpp"

void CollisionHandler::BeginContact(b2Contact *contact) {
    auto body_a = reinterpret_cast<RigidBody &>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
    auto body_b = reinterpret_cast<RigidBody &>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

    ColliderEntryEvent entry_event = ColliderEntryEvent {body_a, body_b};
    Global::get_instance()->notify_event_manager(entry_event);
}

void CollisionHandler::EndContact(b2Contact *contact) {
    auto body_a = reinterpret_cast<RigidBody &>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
    auto body_b = reinterpret_cast<RigidBody &>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

    ColliderExitEvent exit_event = ColliderExitEvent {body_a, body_b};
    Global::get_instance()->notify_event_manager(exit_event);
}
