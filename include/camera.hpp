#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include "gameobject.hpp"
#include "color.hpp"

/**
 * @brief Class representing a point of view towards the game scene.
 */
class Camera : public GameObject
{
private:
    Color _background_color;
    int _aspect_width;
    int _aspect_height;

public:
    /**
     * @brief Constructor.
     * @param aspect_width The initial aspect width of the camera.
     * @param aspect_height The initial aspect height of the camera.
     */
    Camera(int aspect_width, int aspect_height);

    /**
     * @brief The getter of the background color.
     * @returns A Color object of the current background color.
     */
    [[nodiscard]] Color get_background_color() const ;

    /**
     * @brief The setter of the new background color.
     * @param c The new color which will be set.
     */
    void set_background_color(Color c);

    /**
     * @brief The getter of the aspect width.
     * @returns An int value of the current aspect width.
     */
    [[nodiscard]] int get_aspect_width() const ;

    /**
     * @brief The setter of the new aspect width.
     * @param w The new width which will be set.
     */
    void set_aspect_width(int w);

    /**
    * @brief The getter of the aspect height.
    * @returns An int value of the current aspect height.
    */
    [[nodiscard]] int get_aspect_height() const ;

    /**
     * @brief The setter of the new aspect height.
     * @param h The new height which will be set.
     */
    void set_aspect_height(int h);
};

#endif //ENGINE_CAMERA_HPP
