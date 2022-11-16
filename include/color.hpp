#pragma once

class Color {
public:
    Color(int r = 0, int g = 0, int b = 0, int a = 0);
    ~Color();

    int _r;
    int _g;
    int _b;
    int _a;
};