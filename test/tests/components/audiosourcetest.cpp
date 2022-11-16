#include "components/audiosource.hpp"

#include "gtest/gtest.h"

TEST(AudioSourceTest, HasNotBeenPlayed_Active)
{
	AudioSource audio(".\\assets\\sample.wav");
	EXPECT_EQ(audio.get_play_count(), 0);
}

TEST(AudioSourceTest, HasBeenPlayed_Active)
{
	AudioSource audio(".\\assets\\sample.wav", true);
	EXPECT_EQ(audio.get_play_count(), 1);
}

TEST(AudioSourceTest, HasBeenPlayed_NotActiveToActive)
{
	AudioSource audio(".\\assets\\sample.wav", true);
	audio.set_active(false);
	audio.set_active(true);
	EXPECT_EQ(audio.get_play_count(), 2);
}

TEST(AudioSourceTest, HasBeenPlayed)
{
	AudioSource audio(".\\assets\\sample.wav");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 1);
}

TEST(AudioSourceTest, HasNotBeenPlayed_NoFile)
{
	AudioSource audio("");
	audio.play();
	EXPECT_EQ(audio.get_play_count(), 0);
}
