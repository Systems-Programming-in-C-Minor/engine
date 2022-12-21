#include <iostream>
#include "components/audiosource.hpp"

#include "fmt/core.h"

namespace fs = std::filesystem;

void AudioSource::set_active(bool is_active)
{
	active = is_active;
	if (_play_on_awake && active)
		play(_loop);
    if(!active)
        stop();
}

void AudioSource::play(bool looping)
{
	if (!is_regular_file(_audio_clip)) {
		fmt::print("File {} not found\n", _audio_clip.string());
		stop();
		return;
	}

	if (_audio_clip.extension() != ".mp3") {
		fmt::print("Unsupported audio format {}\n", _audio_clip.extension().string());
		stop();
		return;
	}

	_loop = looping;
    _sample->set_looping(_loop);
	_sample->play();
	++_play_count;
}

void AudioSource::stop()
{
    _sample->stop();
}

int AudioSource::get_play_count() const
{
	return _play_count;
}

// TODO Relative path should be resolved using executable directory, not working directory
AudioSource::AudioSource(
	const std::string& audio_clip,
	bool play_on_awake,
	bool loop,
	float volume,
	const std::string name) :
		Component(name),
		_audio_clip(fs::current_path().append(audio_clip)),
		_play_on_awake(play_on_awake),
		_loop(loop),
		_volume(volume)
{
	_sample = std::make_unique<SDLMixerAudioSample>(audio_clip, volume, loop);
	if (_play_on_awake && active)
		play(loop);
}

void AudioSource::resume() {
    _sample->resume();
}

bool AudioSource::is_playing() const {
    return _sample->is_playing();
}
