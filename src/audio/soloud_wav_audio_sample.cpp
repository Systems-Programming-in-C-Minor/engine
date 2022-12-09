#include "audio/soloud_wav_audio_sample.hpp"

#include "soloud_wav.h"

SoloudWavAudioSample::SoloudWavAudioSample() : _soloud_wav_file(std::make_shared<SoLoud::Wav>())
{}

void SoloudWavAudioSample::load(const std::string &path) {
    _soloud_wav_file->load(path.c_str());
}

void SoloudWavAudioSample::set_volume(float volume) {
    _soloud_wav_file->setVolume(volume);
}

void SoloudWavAudioSample::stop() {
    _soloud_wav_file->stop();
}

void SoloudWavAudioSample::set_looping(bool loop) {
    _soloud_wav_file->setLooping(loop);
}
