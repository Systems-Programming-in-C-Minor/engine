#include <gtest/gtest.h>
#include "sound.hpp"

TEST(SoundTest, LoadNPlay) {
    auto sound1 = Sound("./assets/sample.wav");
    sound1.play();
    sleep(5);
    auto sound2 = Sound("./assets/sample.wav");
    sound2.play();
    sound2.setVolume(10.f);
    sleep(5);
}
