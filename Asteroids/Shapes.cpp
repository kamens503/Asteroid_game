#include "Shapes.h"

using namespace Shapes;

typedef std::vector <std::pair<unsigned int, Entities::Entity*>> typelist;

typelist Manager::circles;
typelist Manager::customs;
typelist Manager::buttons;
typelist Manager::texts;

Shapes::Circle::Circle(sf::Vector2f _pos, float _radius, int _points, sf::Color _color)
{
	pos = _pos * scale;
	radius = _radius * scale;
	size = { _radius , _radius };
	color = _color;


	shape.setOrigin(radius * 0.5f, radius * 0.5f);
	shape.setRadius(radius);
	shape.setPosition(pos);
	shape.setPointCount(_points);
	shape.setFillColor(color);

	Manager::record(Manager::circles, (Entities::Entity*)this);
}

Shapes::Circle::~Circle()
{
	Manager::forget(Manager::circles, unique_id, local_id);
}