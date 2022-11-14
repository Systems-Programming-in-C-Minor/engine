#include "components/audiosource.hpp"

#include "gtest/gtest.h"

TEST(AudioSourceTest, HasNotBeenPlayed_Active)
{
	AudioSource audio("sample.wav");
	EXPECT_EQ(audio.get_play_count(), 0);
}

TEST(AudioSourceTest, HasBeenPlayed_Active)
{
	AudioSource audio("sample.wav", true);
	EXPECT_EQ(audio.get_play_count(), 1);
}

TEST(AudioSourceTest, HasBeenPlayed_NotActiveToActive)
{
	AudioSource audio("sample.wav", true);
	audio.setActive(false);
	audio.setActive(true);
	EXPECT_EQ(audio.get_play_count(), 2);
}

TEST(AudioSourceTest, HasBeenPlayed)
{
	AudioSource audio("sample.wav");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 1);
}

TEST(AudioSourceTest, HasNotBeenPlayed_NoFile)
{
	AudioSource audio("");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 0);
}
