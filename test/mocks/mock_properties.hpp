#ifndef ENGINE_MOCK_PROPERTIES_HPP
#define ENGINE_MOCK_PROPERTIES_HPP

#include "gmock/gmock.h"
#include "storage/iproperties.hpp"

class MockProperties : public IProperties {
public:
    MOCK_METHOD(void, set_property, (std::string, std::string), (override));
    MOCK_METHOD(std::optional<std::string>, get_property, (std::string), (override, const));
};

#endif // ENGINE_MOCK_PROPERTIES_HPP
