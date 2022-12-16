
#ifndef ENGINE_RANDOM_HPP
#define ENGINE_RANDOM_HPP

class Random {
public:
    static int random(int max = 1, int min = 0);

    static int random(float max, float min);

    static bool random_bool();
};


#endif //ENGINE_RANDOM_HPP
