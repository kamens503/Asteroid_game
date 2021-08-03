#pragma once
#ifndef __UTIL_H_INCLUDED__
#define __UTIL_H_INCLUDED__

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <functional>


namespace Util
{
	typedef std::function <void()> action;
	const float PI = 3.14159265f;

	sf::Vector2f signed_positive(sf::Vector2f const &_vector);
	sf::Vector2f distance(sf::Vector2f _vectorA, sf::Vector2f _vectorB);

	sf::Vector2f normalize(sf::Vector2f _vector, sf::Vector2f _distance);

	sf::Vector2f cross(sf::Vector2f _vectorA, sf::Vector2f _vectorB);
	struct Dt
	{
		sf::Clock clock;
		float time;
		float update();
		Dt();
	};

	struct Size
	{
		float width,
			height;
	};

	struct Unit_vector
	{
		float x, y;
	};

	struct Scale_vector
	{
		float x, y;
	};

}
#endif