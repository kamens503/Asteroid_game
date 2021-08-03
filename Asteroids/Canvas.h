#pragma once
#ifndef __CANVAS_H_INCLUDED__
#define __CANVAS_H_INCLUDED__
#include "SFML/Graphics.hpp"

namespace Canvas
{
	struct Polygon {
		sf::VertexArray shape;
		sf::Transform transform;
	};

	struct Render_item {
		sf::Drawable* drawable;
		sf::Transform* transform;
		bool has_tranform;
	};
};

#endif