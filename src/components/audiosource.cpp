#include "components/audiosource.hpp"

#include "fmt/core.h"

void AudioSource::setActive(bool isActive)
{
	active = isActive;
	if (m_play_on_awake && active)
		play(m_loop);
	return;
}

void AudioSource::play(bool looping)
{
	// TODO A better way of checking whether a file exists.
	// Sounds like a job for std::filesystem::exists.
	if (!is_regular_file(m_audio_clip)) {
        fmt::print("File {} not found\n", m_audio_clip.string());
        stop();
        return;
	}

    if (m_audio_clip.extension() != ".wav") {
        fmt::print("Unsupported audio format {}\n", m_audio_clip.extension().string());
        stop();
        return;
    }

	m_loop = looping;
	m_is_playing = true;
	// Play audio file here
	++m_play_count;
	stop();
	return;
}

void AudioSource::stop()
{
	if(m_is_playing)
		m_is_playing = false;
	return;
}

int AudioSource::get_play_count()
{
	return m_play_count;
}

AudioSource::AudioSource(
	const std::string& audio_clip,
	bool play_on_awake,
	bool loop,
	double volume) :
	m_audio_clip(fs::current_path().append(audio_clip)),
	m_play_on_awake(play_on_awake),
	m_loop(loop),
	m_volume(volume) 
{
	// Play sample if component is active
	// and play on awake is true
	if (m_play_on_awake && active)
		play(loop);
}
