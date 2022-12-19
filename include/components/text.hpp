#ifndef ENGINE_TEXT_HPP
#define ENGINE_TEXT_HPP

#include "interfaces/irenderable.hpp"
#include "component.hpp"
#include "color.hpp"

#include <string>
#include <memory>

class Text : public Component, public IRenderable {
public:
    unsigned int res_x, res_y;
    float pixels_to_meters;

    Text(const std::string& text,
        const std::string& font_path,
        const int font_size,
        int order_in_layer,
        const Color& foreground_color = Color{ 255, 255, 255, 0 },
        const Color& background_color = Color{ 0, 0, 0, 255 },
        float fps = 30.f,
        float pixels_to_meters = 100.f,
        bool flip_x = false,
        bool flip_y = false
    );

    void render() override;
    void set_text(const std::string & text);
    [[nodiscard]] float get_size_x() const;
    [[nodiscard]] float get_size_y() const;
private:
    std::string _font_path;
    int _font_size;
    Color _foreground_color;
    Color _background_color;
    bool flip_x;
    bool flip_y;
    std::string _prev_text;
    float _fps;
    float _time_since_last_render;
    std::shared_ptr<SdlText> _texture;

    void load_texture(const std::string& text);
    bool should_render();
};

#endif //ENGINE_TEXT_HPP
