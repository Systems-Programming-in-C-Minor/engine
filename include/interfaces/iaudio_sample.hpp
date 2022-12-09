#ifndef ENGINE_IAUDIO_SAMPLE_HPP
#define ENGINE_IAUDIO_SAMPLE_HPP

#include <string>

class IAudioSample {
public:
    virtual void load(const std::string &path) = 0;
    virtual void set_volume(float volume) = 0;
    virtual void stop() = 0;
    virtual void set_looping(bool loop) = 0;
};

#endif //ENGINE_IAUDIO_SAMPLE_HPP
