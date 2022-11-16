#include "audio/soloud_wav_audio_sample.hpp"

void SoLoudWavAudioSample::load(std::string path) const
{
    _wav.load(path);
}

void SoLoudWavAudioSample::stop() const
{
    _wav.stop();
}

void SoLoudWavAudioSample::set_looping(bool loop)
{
    _wav.set_looping(loop);
}

void SoLoudWavAudioSample::set_volume(float volume)
{
    _wav.set_volume(volume);
}
