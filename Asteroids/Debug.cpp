#include "Debug.h"

 bool Debug::Gizmo::visible = true;
 std::vector<std::pair<int,Debug::Gizmo*>> Debug::Manager::gizmo_list;
 unsigned int Debug::Manager::unique_id = 0;

Debug::Line::Line(sf::Vector2f* _start, sf::Vector2f* _end)
{
	Debug::Manager::unique_id++;
	start_point = _start;
	end_point = _end;
	sf::VertexArray line(sf::Lines, 2);

	line[0].position = *_start;
	line[1].position = *_end;

	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;

	shape = line;
	Debug::Manager::gizmo_list.push_back({ Debug::Manager::unique_id, (Gizmo*)this});
}

Debug::Line::~Line()
{
}

void Debug::Line::update()
{
	shape[0].position = *start_point;
	shape[1].position = *end_point;

}

Canvas::Render_item Debug::Line::render()
{
	return { (sf::Drawable*)&shape, nullptr, false };
}

void Debug::Manager::update_gizmos()
{
	for (auto& gizmo : gizmo_list)
	{
		gizmo.second->update();
	}
}
