#include <iostream>
#include "audio/sdl_mixer_sound_engine.hpp"

#include "SDL2pp/Mixer.hh"
#include "SDL2pp/Chunk.hh"


void SDLMixerSoundEngine::play(const std::string &path)
{
    if(!_audio_files.contains(path))
    {
        SDL2pp::Chunk audio_file(Mix_LoadWAV(path.c_str()));
        if (audio_file.Get() == nullptr)
        {
            std::cerr << "Audio file with path: " << path << " could not be loaded" << std::endl;
        }
        _audio_files[path] = std::make_shared<SDL2pp::Chunk>(audio_file.Get());
    }
    Mix_PlayChannel(1, _audio_files[path]->Get(), 1);
}
