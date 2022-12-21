#ifndef ENGINE_SDL_MIXER_AUDIO_SAMPLE_HPP
#define ENGINE_SDL_MIXER_AUDIO_SAMPLE_HPP

#include "interfaces/iaudio_sample.hpp"
#include "interfaces/isound_engine.hpp"
#include <memory>
#include <optional>

namespace SDL2pp {
    class Chunk;
}

class SDLMixerAudioSample : public IAudioSample
{
public:
    SDLMixerAudioSample(std::string path, float volume, bool loop);
    void play() override;
    void set_volume(double volume) override;
    void stop() override;
    void set_looping(bool loop) override;
private:
    std::shared_ptr<ISoundEngine>_sound_engine;
    const std::string _path;
    double _volume;
    bool _loop;
    std::optional<int> _id;
};

#endif //ENGINE_SDL_MIXER_AUDIO_SAMPLE_HPP
