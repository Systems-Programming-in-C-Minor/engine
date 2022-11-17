#ifndef ENGINE_SOLOUD_HPP
#define ENGINE_SOLOUD_HPP

#include "interfaces/iaudiosample.hpp"

class SoLoudImpl
{
public:
    void init();
    void deinit();
    void play(IAudioSample sample);
};

#endif //ENGINE_SOLOUD_HPP
