#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

class Color {
public:
    Color(double red, double green, double blue, double alpha);

    static const Color &white() { return _white; }

    static const Color &red() { return _red; }

    static const Color &green() { return _green; }

    static const Color &blue() { return _blue; }

    static const Color &cyan() { return _cyan; }

    static const Color &magenta() { return _magenta; }

    static const Color &yellow() { return _yellow; }

    static const Color &black() { return _black; }

private:
    double r;
    double g;
    double b;
    double a;

    static Color _white;
    static Color _red;
    static Color _green;
    static Color _blue;
    static Color _cyan;
    static Color _magenta;
    static Color _yellow;
    static Color _black;
};

#endif //ENGINE_COLOR_HPP
