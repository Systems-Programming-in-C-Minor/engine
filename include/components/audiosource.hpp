#ifndef COMPONENTS_AUDIOSOURCE_H_NE8Ak79aUp
#define COMPONENTS_AUDIOSOURCE_H_NE8Ak79aUp

#include "component.hpp"

#include <string>
#include <filesystem>
#include "audio/sdl_mixer_audio_sample.hpp"
#include "interfaces/itickable.hpp"

class GameObject;

/**
 * @brief Component for playback of an audio file.
 */
class AudioSource : public Component, public ITickable
{
public:
	/**
	 * Sets the component's active state.
	 * Plays audio if play on awake is true and component is active.
	 * @param[in] isActive Sets active state.
	 */
	void set_active(bool is_active) override;

	/**
	 * Plays an audio source.
	 * @param[in] looping Automatically replay when sample ends.
	 */
	void play(bool looping = false);

    /**
	 * Resumes the sound.
	 */
	void resume();

    /**
	 * Check whether the sound is currently playing.
	 * @return Whether the sound is currently playing.
	 */
	[[nodiscard]] bool is_playing() const;

	/**
	 * Stops playback if playing.
	 */
	void stop();

	/**
	 * Returns the times a sample has been played.
	 * @return Times this audio source has been played.
	 */
	[[nodiscard]] int get_play_count() const;

	/*
	 *	Tick method for checking if current gameobject that this is attached to is still active
	 *	otherwise, stop playing audio.
	 */
	void tick(GameObject& gameobject) override;

    /**
     * @brief Explicit constructor.
     * @param audio_clip The path to the mp3 audio clip.
     * @param play_on_awake Flag to tell the audio source to play automatically.
     * @param loop Flag to tell the audio source to loop.
     * @param volume Set the initial volume of the audio source.
     * @param name Set the name of the AudioSource.
     */
	explicit AudioSource(
		const std::string& audio_clip,
		bool play_on_awake = false,
		bool loop = false,
    float volume = 1.0,
		const std::string name = ""
	);
private:
	std::filesystem::path _audio_clip;
	bool _play_on_awake;
	bool _loop;
    float _volume;
	int _play_count = 0;
    std::shared_ptr<SDLMixerAudioSample> _sample;
};

#endif // COMPONENTS_AUDIOSOURCE_H_NE8Ak79aUp
