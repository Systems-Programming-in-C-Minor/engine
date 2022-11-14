#ifndef ENGINE_IPROPERTIES_HPP
#define ENGINE_IPROPERTIES_HPP

#include <string>
#include <optional>

using namespace std;

class iproperties {
    virtual void set_property(string name) = 0;

    virtual optional<string> get_property(string name) = 0;
};

#endif //ENGINE_IPROPERTIES_HPP
