#include <utility>
#include <iostream>

#include "audio/sdl_mixer_audio_sample.hpp"
#include "global.hpp"


SDLMixerAudioSample::SDLMixerAudioSample(std::string path, float volume, bool loop) :
    _path(std::move(path)),
    _volume(volume),
    _loop(loop),
    _id(std::nullopt)
    {
        _sound_engine = Global::get_instance()->get_engine().get_sound_engine();
    }

void SDLMixerAudioSample::play()
{
    if (_id.has_value()) {
        _sound_engine->play(_id.value());
    } else {
        _id = _sound_engine->play(_path, _volume, _loop);
    }
}

void SDLMixerAudioSample::stop()
{
    if (_id.has_value()) {
        _sound_engine->stop(_id.value());
    }
}

void SDLMixerAudioSample::set_looping(bool loop)
{
    _loop = loop;
}

void SDLMixerAudioSample::set_volume(double volume)
{
    _volume = volume;
}

void SDLMixerAudioSample::resume() {
    _sound_engine->resume(_id.value());
}

bool SDLMixerAudioSample::is_playing() const {
    if (!_id.has_value())
        return false;

    return _sound_engine->is_playing(_id.value());
}
