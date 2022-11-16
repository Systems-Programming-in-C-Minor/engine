#ifndef ENGINE_SOLOUD_WAV_AUDIO_SAMPLE_HPP
#define ENGINE_SOLOUD_WAV_AUDIO_SAMPLE_HPP

#include "interfaces/iaudiosample.hpp"
#include "wav_impl.hpp"

class SoLoudWavAudioSample : IAudioSample
{
public:
    void load(std::string path) const;
    void set_volume(float volume);
    void stop() const;
    void set_looping(bool loop);
private:
    WavImpl _wav;
};

#endif //ENGINE_SOLOUD_WAV_AUDIO_SAMPLE_HPP
