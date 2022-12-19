#include "components/audiosource.hpp"

#include "gtest/gtest.h"

TEST(AudioSourceTest, HasNotBeenPlayed_Active)
{
	AudioSource audio("./assets/sample.mp3");
	EXPECT_EQ(audio.get_play_count(), 0);
}

TEST(AudioSourceTest, HasBeenPlayed_Active)
{
	const AudioSource audio("./assets/sample.mp3", true);
	EXPECT_EQ(audio.get_play_count(), 1);
}

TEST(AudioSourceTest, HasBeenPlayed_NotActiveToActive)
{
	AudioSource audio("./assets/sample.mp3", true);
	audio.set_active(false);
	audio.set_active(true);
	EXPECT_EQ(audio.get_play_count(), 2);
}

TEST(AudioSourceTest, HasBeenPlayed)
{
	AudioSource audio("./assets/sample.mp3");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 1);
}

TEST(AudioSourceTest, HasNotBeenPlayed_NoFile)
{
	AudioSource audio("");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 0);
}

TEST(AudioSourceTest, HasNotBeenPlayed_WrongFileType)
{
	AudioSource audio("./assets/sample.wav");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 0);
}