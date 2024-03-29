#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include "gameobject.hpp"
#include "color.hpp"

/**
 * @brief Class representing a point of view towards the game scene.
 */
class Camera : public GameObject
{
public:
    /**
     * @brief The background color object of the Camera (Color).
     */
    Color background_color;

    /**
     * @brief The meters to pixel ratio of the Camera.
     */
    float mtp;

    /**
     * @brief The screen space limits of the Camera.
     */
    float screen_space_limits;

    /**
     * @brief Constructor.
     * @param transform The transform of the camera.
     * @param background_color The background color of the camera.
     * @param mtp Meters to pixel ratio.
     * @param screen_space_limits The screen space limits of the camera.
     */
    explicit Camera(
        float mtp = 20.f,
        Transform transform = Transform{},
        const Color& background_color = Color{},
        float screen_space_limits = 200.f
    );

    /**
     * @brief Getter method to return the current background color.
     * @return Returns a Color object.
     */
    [[nodiscard]] Color get_background_color() const;

    /**
     * @brief Setter method for the background color.
     * @param c The Color object which will be set as background color.
     */
    void set_background_color(Color c);
};

#endif //ENGINE_CAMERA_HPP
