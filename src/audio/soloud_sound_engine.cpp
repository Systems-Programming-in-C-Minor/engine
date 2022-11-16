#include "audio/soloud_sound_engine.hpp"

void SoLoudSoundEngine::play(IAudioSample sample)
{
    _engine.play(sample);
}
