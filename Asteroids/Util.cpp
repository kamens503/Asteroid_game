#pragma once
#include "Util.h"

using namespace Util;

sf::Vector2f Util::signed_positive(sf::Vector2f const &_vector)
{
	sf::Vector2f v;
	if (_vector.x > 0) {
		v.x = -_vector.x;
	}
	if (_vector.y > 0) {
		v.y = -_vector.y;
	}
	return v;
}

sf::Vector2f Util::distance(sf::Vector2f _vectorA, sf::Vector2f _vectorB)
{
	sf::Vector2f v;
	_vectorA = signed_positive(_vectorA);
	_vectorB = signed_positive(_vectorB);

	v = _vectorB - _vectorA;
	return v;
}

sf::Vector2f Util::normalize(sf::Vector2f _vector, sf::Vector2f _distance)
{
	sf::Vector2f v;
	v = { _vector.x / _distance.x, _vector.y / _distance.y };
	return v;
}

//sf::Vector2f Util::cross(sf::Vector2f _vectorA, sf::Vector2f _vectorB)
//{
//	sf::Vector2f vectorC;
//
//	vectorC.x = _vectorA.x * _vectorB.y;
//	vectorC.y = _vectorA.y * _vectorB.x;
//}

float Util::Dt::update()
{
	return time = clock.restart().asSeconds();
}

Util::Dt::Dt()
{
	clock = sf::Clock();
	time = 0.f;
}
