#ifndef ENGINE_IKEYLISTENER_HPP
#define ENGINE_IKEYLISTENER_HPP

#include "enums/Key.hpp"

class IKeyListener {

    virtual void on_key_pressed(Key key) = 0;

    virtual void on_key_released(Key key) = 0;

};

#endif //ENGINE_IKEYLISTENER_HPP
