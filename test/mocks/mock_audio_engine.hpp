#ifndef ENGINE_MOCK_AUDIO_ENGINE_HPP
#define ENGINE_MOCK_AUDIO_ENGINE_HPP

#include <gmock/gmock.h>
#include <interfaces/isound_engine.hpp>

class MockAudioEngine : public ISoundEngine {
public:
    MOCK_METHOD(int, play, (const std::string&, double volume, bool loop), (override));

    MOCK_METHOD(void, play, (int), (override));
    MOCK_METHOD(void, resume, (int), (override));
    MOCK_METHOD(void, stop, (int), (override));
    MOCK_METHOD(bool, is_playing, (int), (override, const));
};

#endif //ENGINE_MOCK_AUDIO_ENGINE_HPP
