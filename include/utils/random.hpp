
#ifndef ENGINE_RANDOM_HPP
#define ENGINE_RANDOM_HPP

/**
 * @brief Class to get random values.
 */
class Random {
public:
    /**
     * @brief Method which returns a random integer between a min and max value.
     * @param min The min int value of the randomizer, 0 at default.
     * @param max The max int value of the randomizer, 1 at default.
     * @return A random integer between the min and max value.
     * */
    static int random(int max = 1, int min = 0);

    /**
     * @brief Method which returns a random float between a min and max value.
     * @param min The min float value of the randomizer, 0 at default.
     * @param max The max float value of the randomizer, 1 at default.
     * @return A random int between the min and max value.
     * */
    static int random(float max, float min);

    /**
     * @brief Method which returns a random float between a min and max value.
     * @param min The min float value of the randomizer, 0 at default.
     * @param max The max float value of the randomizer, 1 at default.
     * @return A random float between the min and max value.
     * */
    static float random_float (float min, float max);

    /**
     * @brief Method which returns a random boolean value.
     * @return A random bool value.
     * */
    static bool random_bool();
};


#endif //ENGINE_RANDOM_HPP
