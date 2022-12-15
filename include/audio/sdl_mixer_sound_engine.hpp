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
    void play(const std::string &path, double volume, bool loop) override;
    void stop(const std::string &path) override;
    void load_chunk(const std::string &path);
    ~SDLMixerSoundEngine();
private:
    std::map<std::string, std::shared_ptr<SDL2pp::Chunk>> _audio_files = {};
    std::map<std::string, int> _channels = {};
};

#endif //ENGINE_SDL_MIXER_SOUND_ENGINE_HPP
