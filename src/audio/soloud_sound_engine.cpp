#include "audio/soloud_sound_engine.hpp"

#include "soloud.h"
#include "soloud_wav.h"

SoloudSoundEngine::SoloudSoundEngine() : _soLoud_instance(std::make_shared<SoLoud::Soloud>())
    {
        _soLoud_instance->init();
    }

void SoloudSoundEngine::play(const std::string &path)  {

    if(!_audio_files.contains(path))
    {
        auto audio_file = std::make_shared<SoLoud::Wav>();
        audio_file->load(path.c_str());
        _audio_files[path] = audio_file;
    }
    _soLoud_instance->play(*_audio_files[path]);
}
