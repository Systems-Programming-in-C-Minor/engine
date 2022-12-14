#include "audio/sdl_mixer_sound_engine.hpp"

#include "SDL2pp/Mixer.hh"
#include "SDL2pp/Chunk.hh"


SDLMixerSoundEngine::SDLMixerSoundEngine()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void SDLMixerSoundEngine::play(const std::string &path)
{
    if(!_audio_files.contains(path))
    {
        auto audio_file = std::make_shared<SDL2pp::Chunk>(Mix_LoadWAV(path.c_str()));
        _audio_files[path] = audio_file;
    }
    Mix_PlayChannel(1, _audio_files[path]->Get(), 10);
}

SDLMixerSoundEngine::~SDLMixerSoundEngine()
{
    Mix_CloseAudio();
}
