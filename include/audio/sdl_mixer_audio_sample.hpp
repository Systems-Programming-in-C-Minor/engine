#ifndef ENGINE_SDL_MIXER_AUDIO_SAMPLE_HPP
#define ENGINE_SDL_MIXER_AUDIO_SAMPLE_HPP

#include "interfaces/iaudio_sample.hpp"
#include <memory>

namespace SDL2pp {
    class Chunk;
}

class SDLMixerAudioSample : public IAudioSample
{
public:
    void play(const std::string &path) override;
    void set_volume(double volume) override;
    void stop() override;
    void set_looping(bool loop) override;
private:
    std::shared_ptr<SDL2pp::Chunk> _audio_file;
};

#endif //ENGINE_SDL_MIXER_AUDIO_SAMPLE_HPP
