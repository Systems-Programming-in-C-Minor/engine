#ifndef ENGINE_ISOUND_ENGINE_HPP
#define ENGINE_ISOUND_ENGINE_HPP

#include <string>

class ISoundEngine {
public:
    virtual int play(const std::string &path, double volume, bool loop) = 0;
    virtual void play(int id) = 0;
    virtual void resume(int id) = 0;
    virtual void stop(int id) = 0;
    [[nodiscard]] virtual bool is_playing(int id) const = 0;
};

#endif //ENGINE_ISOUND_ENGINE_HPP
