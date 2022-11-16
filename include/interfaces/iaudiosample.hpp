#ifndef ENGINE_IAUDIOSAMPLE_HPP
#define ENGINE_IAUDIOSAMPLE_HPP

#include <string>

class IAudioSample {
public:
    virtual void load(std::string path) const;
    virtual void set_volume(float volume);
    virtual void stop() const;
    virtual void set_looping(bool loop);
};

#endif //ENGINE_IAUDIOSAMPLE_HPP
