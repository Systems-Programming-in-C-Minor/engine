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

	if (_audio_clip.extension() != ".wav") {
		fmt::print("Unsupported audio format {}\n", _audio_clip.extension().string());
		stop();
		return;
	}

	_loop = looping;
    _sample->set_looping(_loop);
	_is_playing = true;
	_sample->play();
	++_play_count;
}

void AudioSource::stop()
{
    _sample->stop();
	_is_playing = false;
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
	float volume) :
	_audio_clip(fs::current_path().append(audio_clip)),
	_play_on_awake(play_on_awake),
	_loop(loop),
	_volume(volume) 
{
	_sample = std::make_unique<SDLMixerAudioSample>(audio_clip, volume, loop);
	if (_play_on_awake && active)
		play(loop);
}
