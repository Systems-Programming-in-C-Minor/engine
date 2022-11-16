#ifndef ENGINE_SOLOUD_SOUND_ENGINE_HPP
#define ENGINE_SOLOUD_SOUND_ENGINE_HPP

#include "interfaces/isoundengine.hpp"
#include "soloud_impl.hpp"

class SoLoudSoundEngine : ISoundEngine
{
public:
    void play(IAudioSample sample);
private:
    SoLoudImpl _engine;
};

#endif //ENGINE_SOLOUD_SOUND_ENGINE_HPP
