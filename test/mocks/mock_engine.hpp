#ifndef ENGINE_MOCK_ENGINE_HPP
#define ENGINE_MOCK_ENGINE_HPP

#include "gmock/gmock.h"
#include "engine.hpp"
#include "mock_renderer.hpp"
#include "mock_audio_engine.hpp"

class MockEngine : public Engine {
public:
    MockEngine() : Engine(std::make_shared<MockRenderer>(), std::make_shared<MockAudioEngine>()) {};
    MOCK_METHOD(const Scene &, get_active_scene, (), (override, const));
    MOCK_METHOD(Scene &, get_active_scene, (), (override));
    MOCK_METHOD(std::shared_ptr<IRenderer>, get_renderer, (), (override, const));
};

#endif // ENGINE_MOCK_ENGINE_HPP
