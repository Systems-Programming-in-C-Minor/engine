
#ifndef ENGINE_COLLISION_HANDLER_HPP
#define ENGINE_COLLISION_HANDLER_HPP

#include "box2d/box2d.h"

class CollisionHandler : public b2ContactListener
{
    void BeginContact(b2Contact* contact) override {

//        //check if fixture A was a ball
//        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
//        if ( bodyUserData )
//            static_cast<Ball*>( bodyUserData )->startContact();
//
//        //check if fixture B was a ball
//        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
//        if ( bodyUserData )
//            static_cast<Ball*>( bodyUserData )->startContact();

    }

    void EndContact(b2Contact* contact) override {

//        //check if fixture A was a ball
//        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
//        if ( bodyUserData )
//            static_cast<Ball*>( bodyUserData )->endContact();
//
//        //check if fixture B was a ball
//        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
//        if ( bodyUserData )
//            static_cast<Ball*>( bodyUserData )->endContact();

    }
};

#endif //ENGINE_COLLISION_HANDLER_HPP
