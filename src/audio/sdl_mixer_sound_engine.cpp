#include <iostream>
#include "audio/sdl_mixer_sound_engine.hpp"

#include "SDL2pp/Mixer.hh"
#include "SDL2pp/Chunk.hh"


SDLMixerSoundEngine::SDLMixerSoundEngine()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
        std::cerr << Mix_GetError() << std::endl;
}

void SDLMixerSoundEngine::load_chunk(int id, const std::string &path)
{
    auto audio_file = std::make_shared<SDL2pp::Chunk>(Mix_LoadWAV(path.c_str()));
    if (audio_file->Get() == nullptr)
    {
        std::cerr << Mix_GetError() << std::endl;
    }
    _audio_samples[id] = audio_file;
}

int SDLMixerSoundEngine::play(const std::string &path, double volume, bool loop)
{
    const auto id = static_cast<int>(_channels.size());

    load_chunk(id, path);
    int channel_number = Mix_PlayChannel(-1, _audio_samples[id]->Get(), loop ? -1 : 0);
    _channels.insert_or_assign(id, channel_number);


    // max volume = 128
    int converted_volume = static_cast<int>(128 * volume);
    if(converted_volume > MIX_MAX_VOLUME)
        converted_volume = MIX_MAX_VOLUME;
    Mix_Volume(_channels[id], converted_volume);

    return id;
}

void SDLMixerSoundEngine::stop(int id)
{
    if(_audio_samples.contains(id)) {
        Mix_Pause(_channels[id]);
    }
}

SDLMixerSoundEngine::~SDLMixerSoundEngine()
{
    Mix_CloseAudio();
}

void SDLMixerSoundEngine::resume(int id) {
    // channel number exists, continue playing
    Mix_Resume(_channels[id]);
}

void SDLMixerSoundEngine::play(int id) {
    Mix_PlayChannel(_channels[id], _audio_samples[id]->Get(), 0);
    Mix_Resume(_channels[id]);
}

bool SDLMixerSoundEngine::is_playing(int id) const {
    return Mix_Playing(id) != 0 && Mix_Paused(id) == 0;
}
