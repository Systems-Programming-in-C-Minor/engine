#ifndef ENGINE_WAV_IMPL_HPP
#define ENGINE_WAV_IMPL_HPP

#include <string>

class WavImpl
{
public:
    void load(std::string path) const;
    void set_volume(float volume);
    void stop() const;
    void set_looping(bool loop);
};

#endif //ENGINE_WAV_IMPL_HPP
