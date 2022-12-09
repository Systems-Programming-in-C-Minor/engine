#ifndef ENGINE_SOLOUD_WAV_AUDIO_SAMPLE_HPP
#define ENGINE_SOLOUD_WAV_AUDIO_SAMPLE_HPP

#include "interfaces/iaudio_sample.hpp"
#include <memory>

namespace SoLoud {
    class Wav;
}

class SoloudWavAudioSample : public IAudioSample {

public:
    SoloudWavAudioSample();
    void load(const std::string &path) override;
    void set_volume(float volume) override;
    void stop() override;
    void set_looping(bool loop) override;
private:
    std::shared_ptr<SoLoud::Wav> _soloud_wav_file;
};

#endif //ENGINE_SOLOUD_WAV_AUDIO_SAMPLE_HPP
