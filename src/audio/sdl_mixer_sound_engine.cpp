#include <iostream>
#include "audio/sdl_mixer_sound_engine.hpp"

#include "SDL2pp/Mixer.hh"
#include "SDL2pp/Chunk.hh"


SDLMixerSoundEngine::SDLMixerSoundEngine()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
        std::cerr << Mix_GetError() << std::endl;
}

void SDLMixerSoundEngine::load_chunk(const std::string &path)
{
    auto audio_file = std::make_shared<SDL2pp::Chunk>(Mix_LoadWAV(path.c_str()));
    if (audio_file->Get() == nullptr)
    {
        std::cerr << Mix_GetError() << std::endl;
    }
    _audio_files[path] = audio_file;
}

void SDLMixerSoundEngine::play(const std::string &path, double volume, bool loop)
{
    if(!_audio_files.contains(path))
    {
        load_chunk(path);
        int channel_number = Mix_PlayChannel(-1, _audio_files[path]->Get(), loop ? -1 : 0);
        _channels.insert_or_assign(path, channel_number);
    }
    else
    {
        // channel number exists, continue playing
        Mix_Resume(_channels[path]);
    }

    // max volume = 128
    int converted_volume = (int) (128 * volume);
    if(converted_volume > MIX_MAX_VOLUME)
        converted_volume = MIX_MAX_VOLUME;
    Mix_Volume(_channels[path], converted_volume);
}

void SDLMixerSoundEngine::stop(const std::string &path)
{
    int channel_number = _channels[path];
    Mix_Pause(channel_number);
}

SDLMixerSoundEngine::~SDLMixerSoundEngine()
{
    Mix_CloseAudio();
}
