#include "camera.hpp"
#include "color.hpp"

Camera::Camera(Transform transform, const Color& background_color, float mtp, float screen_space_limits) :
    GameObject("camera", "camera", transform),
    background_color(background_color),
    mtp(mtp),
	screen_space_limits(screen_space_limits)
{ }

Color Camera::get_background_color() const {
    return background_color;
}
void Camera::set_background_color(Color c) {
    background_color = c;
}
