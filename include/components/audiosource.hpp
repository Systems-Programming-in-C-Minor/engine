#ifndef COMPONENTS_AUDIOSOURCE_H_NE8Ak79aUp
#define COMPONENTS_AUDIOSOURCE_H_NE8Ak79aUp

#include "component.hpp"

#include <string>
#include <filesystem>

/**
 * Component for playback of an audio file.
 */
class AudioSource : public Component
{
public:
	/**
	 * Sets the component's active state
	 * Plays audio if play on awake is true and component is active
	 * 
	 * @param[in] isActive Sets active state
	 */
	virtual void set_active(bool is_active) override;

	/**
	 * Plays an audio source
	 * 
	 * @param[in] looping Automatically replay when sample ends
	 */
	void play(bool looping = false);

	/**
	 * Stops playback if playing
	 */
	void stop();

	/**
	 * Returns the times a sample has been played
	 * 
	 * @return Times this audiosource has been played
	 */
	int get_play_count();

	AudioSource(
		const std::string& audio_clip,
		bool play_on_awake = false,
		bool loop = false,
		double volume = 1.0
	);
private:
	std::filesystem::path m_audio_clip;
	bool _play_on_awake;
	bool _loop;
	double _volume;

	bool _is_playing = false;
	int _play_count = 0;
};

#endif // COMPONENTS_AUDIOSOURCE_H_NE8Ak79aUp
