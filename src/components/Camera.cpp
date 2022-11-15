#include "components/Camera.hpp"

Color Camera::get_background_color(){
    return _background_color;
}
void Camera::set_background_color(Color c){
    _background_color = c;
}
int Camera::get_aspect_width(){
    return _aspect_width;
}
void Camera::set_aspect_width(int w){
    _aspect_width = w;
}
int Camera::get_aspect_height(){
    return _aspect_height;
}
void Camera::set_aspect_height(int h){
    _aspect_height = h;
}

