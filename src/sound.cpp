#include "sound.hpp"

#include <memory>
#include "soloud.h"
#include "soloud_wav.h"

Sound::Sound(const std::string& path) : soLoud_instance(std::make_shared<SoLoud::Soloud>()),
                 sound_file(std::make_shared<SoLoud::Wav>()) {
    soLoud_instance->init();
    sound_file->load(path.c_str());
}

void Sound::play() {
    handle = soLoud_instance->play(*sound_file);
}

void Sound::setVolume(float volume) {
    soLoud_instance->setVolume(handle, volume);
}
