#ifndef ENGINE_SOUND_HPP
#define ENGINE_SOUND_HPP

#include <memory>

namespace SoLoud {
    class Soloud;
    class Wav;
}

class Sound {
private:
    std::shared_ptr<SoLoud::Soloud> soLoud_instance;
    std::shared_ptr<SoLoud::Wav> sound_file;
    unsigned int handle{};
public:
    explicit Sound(const std::string& path);
    void play();

    void setVolume(float volume);
};

#endif // ENGINE_SOUND_HPP
