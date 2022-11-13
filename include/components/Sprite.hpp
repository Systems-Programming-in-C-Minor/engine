//
// Created by lars on 13-11-22.
//

#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include "renderer/IRenderable.hpp"
#include "string"
#include "Component.hpp"
#include "Color.hpp"
#include "renderer/ITexture.hpp"
#include "memory"

using namespace std;

class Sprite : public Component, public IRenderable {
public:
    Sprite(string sprite, Color color, bool flipX, bool flipY, int sortingLayer, int orderInLayer);

    void render(IRenderer &renderer, bool isWorldSpace = true) const override;

private:
    std::string sprite;
    Color color;
    bool flipX;
    bool flipY;
    int sortingLayer;
    int orderInLayer;

    unique_ptr<ITexture> texture;
};

#endif //ENGINE_SPRITE_HPP
