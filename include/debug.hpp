#ifndef ENGINE_DEBUG_HPP
#define ENGINE_DEBUG_HPP

#include "color.hpp"
#include "vector2d.hpp"

/**
 * @brief Some convenient debugging functions.
 */
class Debug {
public:
    /**
     * @brief Draws a colored line between specified start and end points.
     * @param start The starting point.
     * @param end The end point.
     * @param color The line color, defaults to white.
     */
    void static draw_line(const Vector2d& start, const Vector2d& end, const Color& color);

    /**
     * @brief Logs a message to the Console.
     * @param message The message to write.
     */
    void static log(const std::string& message);

    /**
     * @brief A variant of Debug.Log that logs an error message to the console.
     * @param error The message to write.
     */
    void static log_error(const std::string& error);

    /**
     * @brief A variant of Debug.Log that logs a warning message to the console.
     * @param warning The message to write.
     */
    void static log_warning(const std::string& warning);

};

#endif //ENGINE_DEBUG_HPP
