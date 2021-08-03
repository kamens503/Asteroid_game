#pragma once
#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include "SFML/Graphics.hpp"
#include "Util.h"
#include "Component.h"
#include <iostream>
#include "Canvas.h"
#include "Palette.h"

class Player
{
public:
	typedef sf::Keyboard::Key sf_key;

	sf::Vector2f position;
	sf::Vector2f size;
	float orientation;

	std::vector <Component::Input_listener> inputs;

	Player(Palette::Color _colorA, Palette::Color _color_B, float *_dt);
	Canvas::Polygon set_shape(Palette::Color _colorA, Palette::Color _color_B);
	Canvas::Render_item render();
	void set_movement(sf_key _up, sf_key _down, sf_key _left, sf_key _right);

	void move(Util::Unit_vector _direction);

	void set_kinetic(float _velocity, float _max_velocity);

	void set_position(sf::Vector2f _pos);
	void rotate(float _angle);

	Canvas::Polygon body;
	
private:
	float* dt_ptr;
	float velocity;
	float max_velocity;
	
};
#endif
