//
// Created by lars on 12-11-22.
//

#ifndef ENGINE_IPROPERTIES_HPP
#define ENGINE_IPROPERTIES_HPP

#include <string>
#include <optional>

using namespace std;

class IProperties {
    virtual void setProperty(string name) = 0;

    virtual optional<string> getProperty(string name) = 0;
};

#endif //ENGINE_IPROPERTIES_HPP
