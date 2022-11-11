//
// Created by Laerositus on 11/11/2022.
//
#include "components/Camera.hpp"

Color Camera::get_background_color(){
    return m_background_color;
}
void Camera::set_background_color(Color c){
    m_background_color = c;
}
int Camera::get_aspect_width(){
    return m_aspect_width;
}
void Camera::set_aspect_width(int w){
    m_aspect_width = w;
}
int Camera::get_aspect_height(){
    return m_aspect_height;
}
void Camera::set_aspect_height(int h){
    m_aspect_height = h;
}

