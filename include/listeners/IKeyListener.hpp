//
// Created by lars on 12-11-22.
//

#ifndef ENGINE_IKEYLISTENER_HPP
#define ENGINE_IKEYLISTENER_HPP

#include "enums/Key.hpp"

class IKeyListener {

    virtual void onKeyPressed(Key key) = 0;

    virtual void onKeyReleased(Key key) = 0;

};

#endif //ENGINE_IKEYLISTENER_HPP
