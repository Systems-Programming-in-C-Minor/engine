#pragma once

class Color {
public:
    Color(int r = 0, int g = 0, int b = 0, int a = 0);
    ~Color() = default;

    int _r;
    int _g;
    int _b;
    int _a;

[[nodiscard]] bool equals(const Color &other) const;
[[nodiscard]] bool operator==(const Color &other) const;
};

