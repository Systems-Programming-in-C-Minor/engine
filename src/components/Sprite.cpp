//
// Created by lars on 13-11-22.
//

#include "components/Sprite.hpp"

Sprite::Sprite(std::string sprite, Color color, bool flipX, bool flipY, int sortingLayer, int orderInLayer) :
        sprite(std::move(sprite)),
        color(color),
        flipX(flipX),
        flipY(flipY),
        sortingLayer(sortingLayer),
        orderInLayer(orderInLayer) {}

void Sprite::render(IRenderer &renderer, bool isWorldSpace) const {
    renderer.renderSprite(*this, *texture, isWorldSpace);
}
