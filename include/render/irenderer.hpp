#pragma once

class IRenderer {
public:
    bool operator==(const IRenderer &other) const {
        return true;
    };
};