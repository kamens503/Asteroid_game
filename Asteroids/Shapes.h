#pragma once
#include "Entities.h"
#include "Util.h"

namespace Shapes {
	
	class Manager : public Entities::Manager
	{
	public:
		static typelist circles, 
						customs,
						buttons,
						texts;
	};

	class Shape : public Entities::Drawable
	{
		
	};

	class Circle : public Shape
	{
	protected:
		float radius;
		sf::CircleShape shape;
	public:
		Circle(sf::Vector2f _pos, float _radius, int _points, sf::Color _color);
		~Circle();
	};

	class Custom : public Entities::Drawable
	{

	};

	class Text : public Entities::Drawable
	{

	};
}


