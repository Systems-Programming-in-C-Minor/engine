//
// Created by Laerositus on 11/11/2022.
//
#include "components/RigidBody.hpp"

//void RigidBody::apply_force(Vector2d force){
//
//}
//void RigidBody::apply_torque(float torque){
//
//}
//
//void RigidBody::set_linear_velocity(Vector2d velocity) {
//
//}
//Vector2d RigidBody::get_linear_velocity(){
//
//}
//
//void RigidBody::set_angular_velocity(float angle){
//
//}
//float RigidBody::get_angular_velocity(){
//
//}
//
//void RigidBody::apply_linear_impulse(Vector2d inpulse){
//
//}
//void RigidBody::apply_angular_impulse(Vector2d impulse){
//
//}

double RigidBody::get_mass(){
    return _mass;
}
void RigidBody::set_mass(double m){
    _mass = m;
}
double RigidBody::get_gravity_scale(){
    return _gravity_scale;
}
void RigidBody::set_gravity_scale(double gs){
    _gravity_scale = gs;
}
BodyType RigidBody::get_bodytype(){
    return _bodytype;
}
void RigidBody::set_bodytype(BodyType bt){
    _bodytype = bt;
}
