#include "camera.hpp"
#include "color.hpp"

Camera::Camera(int aspect_width, int aspect_height, bool is_world_space, Transform transform, const Color& background_color, int mtp) :
    GameObject("camera", "camera", is_world_space, transform),
    background_color(background_color),
	aspect_width(aspect_width),
    aspect_height(aspect_height),
    mtp(mtp)
{ }

Color Camera::get_background_color() const {
    return background_color;
}
void Camera::set_background_color(Color c) {
    background_color = c;
}
int Camera::get_aspect_width() const {
    return aspect_width;
}
void Camera::set_aspect_width(int w) {
    aspect_width = w;
}
int Camera::get_aspect_height() const {
    return aspect_height;
}
void Camera::set_aspect_height(int h) {
    aspect_height = h;
}
