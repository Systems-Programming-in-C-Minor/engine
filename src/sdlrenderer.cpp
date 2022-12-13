#include "transform.hpp"
#include "render/itexture.hpp"
#include "uiobjects/text.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "sdlrenderer.hpp"
#include "utils/exceptionhandlers.hpp"
#include "vector2d.hpp"
#include "utils/trigonometry.hpp"
#include "rendercall.hpp"

#include "SDL.h"
#include "SDL2pp/SDL.hh"
#include "SDL2pp/Renderer.hh"
#include "SDL2pp/Window.hh"
#include "SDL2pp/Color.hh"
#include "SDL2pp/SDLImage.hh"
#include "SDL2pp/Exception.hh"
#include "SDL2pp/Point.hh"
#include "box2d/box2d.h"

#include <cmath>
#include <ostream>
#include <utility>

void SdlRenderer::render_sprite(const Sprite& sprite, ITexture& texture, Transform& transform, bool is_world_space) const
{
	/*
	 * TODO Open PR for SDL2pp
	 * Segfaults, SDL2pp needs to fix this
	 * int x = _renderer->GetOutputWidth();
	 * int x, y = 0;
	 * SDL_GetRendererOutputSize(_renderer->Get(), &x, nullptr);
	 */

	const float left_corner_x = transform.get_position().x + -sprite.get_size_x() * transform.get_scale() / 2.f;
	const float left_corner_y = transform.get_position().y + sprite.get_size_y() * transform.get_scale() / 2.f;

	const auto center = world_to_screen(transform.get_position());
	const auto left_corner = world_to_screen(Vector2d{ left_corner_x, left_corner_y });

	const int size_x = static_cast<int>(round(sprite.get_size_x() * transform.get_scale() * _mtp));
	const int size_y = static_cast<int>(round(sprite.get_size_y() * transform.get_scale() * _mtp));
	const auto size = SDL2pp::Point{ size_x, size_y };

	auto rect = SDL2pp::Rect{ left_corner, size };
	_renderer->Copy(*texture.get_texture(), SDL2pp::NullOpt, rect, -radians_to_degrees(transform.get_angle()));
}

void SdlRenderer::render_rigid_body(const RigidBody& rigid_body, Transform& transform, bool is_world_space) const
{
	b2Body* body = rigid_body.get_body();
	b2Shape* shape = body->GetFixtureList()->GetShape();
	switch(shape->GetType())
	{
		// NOLINTBEGIN(bugprone-branch-clone)
		case b2Shape::Type::e_circle: break;
		case b2Shape::Type::e_polygon:
			{
				render_ngon(body, dynamic_cast<b2PolygonShape*>(shape));
				break;
			}
		case b2Shape::Type::e_chain:
			{
				render_ngon(body, dynamic_cast<b2ChainShape*>(shape));
				break;
			}
		case b2Shape::e_edge: break;
		case b2Shape::e_typeCount: break;
		// NOLINTEND(bugprone-branch-clone)
	}

}

void SdlRenderer::render_ngon(b2Body* body, b2PolygonShape* shape) const
{
	const int vertex_count = shape->m_count;

	std::vector<Vector2d> vectors;
	vectors.reserve(vertex_count);

	for (int i = 0; i < vertex_count; ++i) {
		vectors.push_back(static_cast<Vector2d>(body->GetWorldPoint(shape->m_vertices[i])));
	}

	const Vector2d start_vertex = vectors[0];
	vectors.push_back(start_vertex);

	render_lines(vectors, Color{ 255, 255,0,0 });
}

void SdlRenderer::render_ngon(b2Body* body, b2ChainShape* shape) const
{
	const int vertex_count = shape->m_count;

	std::vector<Vector2d> vectors;
	vectors.reserve(vertex_count);

	for (int i = 0; i < vertex_count; ++i) {
		vectors.push_back(static_cast<Vector2d>(body->GetWorldPoint(shape->m_vertices[i])));
	}

	const Vector2d start_vertex = vectors[0];
	vectors.push_back(start_vertex);

	render_lines(vectors, Color{ 255, 255,0,0 });
}

void SdlRenderer::render_lines(std::vector<Vector2d>& vectors, const Color& color) const
{
	std::vector<SDL2pp::Point> points;
	points.reserve(vectors.size());

	for(auto& vector : vectors) {
		points.push_back(world_to_screen(vector));
	}
	_renderer->SetDrawColor(static_cast<SDL2pp::Color>(color));
	_renderer->DrawLines(points.data(), static_cast<int>(points.size()));
}

void SdlRenderer::render_text(Text& text) const
{
	/**
	 * TODO Task: Render text
	 * https://app.clickup.com/t/358vh7v
	 */
}

void SdlRenderer::clear(const Color& color) const try
{
	const auto _color = static_cast<SDL2pp::Color>(color);
	_renderer->SetDrawColor(_color).Clear();
} catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::push_to_screen() try
{
	_render_queue.sort([](const RenderCall& p1, const RenderCall& p2)
		{
			return p1.order_in_layer < p2.order_in_layer;
		});

	for (const auto& render_call : _render_queue) {
		render_call.render_callback();
	}
	_renderer->Present();
} catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::init(int res_x, int res_y) try 
{
	_sdl = std::make_unique<SDL2pp::SDL>(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	_sdl_image = std::make_unique<SDL2pp::SDLImage>();

	_window = std::make_shared<SDL2pp::Window>("UnEngine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		res_x, res_y,
		SDL_WINDOW_RESIZABLE);

	_renderer = std::make_shared<SDL2pp::Renderer>(*_window, -1, SDL_RENDERER_ACCELERATED);
} catch (SDL2pp::Exception& e) { handle_fatal_exception(e); }

void SdlRenderer::add_render_call(RenderCall& render_call) {
	_render_queue.push_back(render_call);
}

SDL2pp::Point SdlRenderer::world_to_screen(const Vector2d& position) const
{
	// TODO Optimization: only retrieve when resolution changes
	const SDL2pp::Point res = _renderer->GetOutputSize();
	const SDL2pp::Point return_pos{
		static_cast<int>(round(static_cast<float>(res.GetX()) * 0.5f + position.x * _mtp)),
		static_cast<int>(round(static_cast<float>(res.GetY()) * 0.5f - position.y * _mtp))
	};
	return return_pos;
}

std::shared_ptr<SDL2pp::Renderer> SdlRenderer::get_renderer()
{
	return _renderer;
}

SdlRenderer::SdlRenderer(int res_x, int res_y)
{
	init(res_x, res_y);
}

SdlRenderer::~SdlRenderer() = default;
