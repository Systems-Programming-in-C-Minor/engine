#include "debug.hpp"
#include "global.hpp"

#include <iostream>

#include "rendercall.hpp"


void Debug::log(const std::string &message)
{
    std::cout << "INFO - " << message << std::endl;
}

void Debug::log_warning(const std::string &warning)
{
    std::cerr << "WARNING - " << warning << std::endl;
}

void Debug::log_error(const std::string &error)
{
    std::cerr << "ERROR - " << error << std::endl;
}

void Debug::draw_line(const Vector2d &start, const Vector2d &end, const Color &color)
{
    const std::vector<Vector2d> vector = { start , end };

    const auto renderer = Global::get_instance()->get_engine().get_renderer();
    auto render_call = RenderCall([renderer, vector, color]() {
        renderer->render_lines(vector, color);
        }, 999);
    renderer->add_render_call(render_call);
}
