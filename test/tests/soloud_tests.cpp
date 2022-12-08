#include <gtest/gtest.h>
#include <unistd.h>
#include "audio/soloud_sound_engine.hpp"

TEST(SoundTest, LoadAndPlayFile) {
    auto engine = SoloudSoundEngine();
    engine.play("./assets/sample2.wav");
    sleep(1);
    engine.play("./assets/sample.wav");
    sleep(1);
    engine.play("./assets/sample.wav");
    sleep(1);
}
