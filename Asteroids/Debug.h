#pragma once

#ifndef __DEBUG_H__
#define __DEBUG_H__
#include "SFML/Graphics.hpp"
#include "Canvas.h"
#include <vector>

namespace Debug
{
	class Gizmo
	{
	public:
		virtual void update() = 0;
		static bool visible;
	private:

	};

	struct Manager
	{
		static unsigned int unique_id;
		static std::vector<std::pair<int, Gizmo*>> gizmo_list;
		static void update_gizmos();

	};

	class Line : public Gizmo
	{
	public:
		sf::Vector2f* start_point;
		sf::Vector2f* end_point;
		sf::VertexArray shape;
			Line(sf::Vector2f* _start, sf::Vector2f* _end);
		~Line();
		void update();

		Canvas::Render_item render();

	};

	struct Circle
	{
		sf::CircleShape shape;
	};
};
#endif // !__DEBUG_H__


