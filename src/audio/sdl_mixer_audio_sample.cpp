#include <utility>

#include "audio/sdl_mixer_audio_sample.hpp"
#include "global.hpp"


SDLMixerAudioSample::SDLMixerAudioSample(std::string path, float volume, bool loop) :
    _path(std::move(path)),
    _volume(volume),
    _loop(loop)
    {
        _sound_engine = Global::get_instance()->get_engine().get_sound_engine();
    }

void SDLMixerAudioSample::play()
{
    _sound_engine->play(_path, _volume, _loop);
}

void SDLMixerAudioSample::stop()
{
    _sound_engine->stop(_path);
}

void SDLMixerAudioSample::set_looping(bool loop)
{
    _loop = loop;
}

void SDLMixerAudioSample::set_volume(double volume)
{
    _volume = volume;
}
