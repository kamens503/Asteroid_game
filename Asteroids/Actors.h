#pragma once
#include "Shapes.h"
#include "Components.h"

namespace Actors
{

	class Actor
	{
	protected:
		int life;
	public:
		int get_life();
		void set_life();
		bool is_alive();
	};

	class Player : public Actor
	{
	public:
		Player();
		~Player();
		Shapes::Shape* shape;
		Components::kinematic physic;
		//sf::Drawable* get_drawable();
	};

}
