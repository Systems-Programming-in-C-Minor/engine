#ifndef ENGINE_SDL_MIXER_SOUND_ENGINE_HPP
#define ENGINE_SDL_MIXER_SOUND_ENGINE_HPP

#include "interfaces/isound_engine.hpp"
#include <memory>
#include <map>

namespace SDL2pp {
    class Chunk;
}

class SDLMixerSoundEngine : public ISoundEngine {

public:
    SDLMixerSoundEngine();

    int play(const std::string &path, double volume, bool loop) override;

    void resume(int id) override;

    void stop(int id) override;

    ~SDLMixerSoundEngine();

private:
    void load_chunk(int id, const std::string &path);

    std::map<int, std::shared_ptr<SDL2pp::Chunk>> _audio_samples = {};
    std::map<int, int> _channels = {};
};

#endif //ENGINE_SDL_MIXER_SOUND_ENGINE_HPP
