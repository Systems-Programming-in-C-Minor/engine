#ifndef ENGINE_MOCK_AUDIO_ENGINE_HPP
#define ENGINE_MOCK_AUDIO_ENGINE_HPP

#include <gmock/gmock.h>
#include <interfaces/isound_engine.hpp>

class MockAudioEngine : public ISoundEngine {
public:
    MOCK_METHOD(void, play, (const std::string&, double volume, bool loop), (override));
    MOCK_METHOD(void, stop, (const std::string&), (override));
    MOCK_METHOD(void, load_chunk, (const std::string&), ());
};

#endif //ENGINE_MOCK_AUDIO_ENGINE_HPP
