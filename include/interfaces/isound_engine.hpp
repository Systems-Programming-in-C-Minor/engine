#ifndef ENGINE_ISOUND_ENGINE_HPP
#define ENGINE_ISOUND_ENGINE_HPP

#include <string>

class ISoundEngine {
public:
    virtual void play(const std::string &path, double volume, bool loop) = 0;
};

#endif //ENGINE_ISOUND_ENGINE_HPP
