//
// Created by lars on 12-11-22.
//

#ifndef ENGINE_IMOUSELISTENER_HPP
#define ENGINE_IMOUSELISTENER_HPP

#include "enums/MouseInput.hpp"

class IMouseListener {

    virtual void OnMouseMoved() = 0;

    virtual void OnMouseClicked(MouseInput button) = 0;

    virtual void OnMousePressed(MouseInput button) = 0;

    virtual void OnMouseReleased(MouseInput button) = 0;

};

#endif //ENGINE_IMOUSELISTENER_HPP
