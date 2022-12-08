#ifndef ENGINE_SOLOUD_SOUND_ENGINE_HPP
#define ENGINE_SOLOUD_SOUND_ENGINE_HPP

#include "interfaces/isound_engine.hpp"
#include <memory>
#include <map>

namespace SoLoud {
    class Soloud;
    class Wav;
}

class SoloudSoundEngine : public ISoundEngine {

public:
    SoloudSoundEngine();
    void play(const std::string &path) override;
private:
    std::shared_ptr<SoLoud::Soloud> _soLoud_instance;
    std::map<std::string, std::shared_ptr<SoLoud::Wav>> _audio_files = {};
};

#endif //ENGINE_SOLOUD_SOUND_ENGINE_HPP
