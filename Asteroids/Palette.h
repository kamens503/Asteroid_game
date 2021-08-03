#pragma once

#ifndef __PALETTE_H_INCLUDED__
#define __PALETTE_H_INCLUDED__
#include "SFML/Graphics.hpp"
#include <iostream>

namespace Palette
{
	struct Color {
		sf::Uint8 r, g, b, a;
		void set_to(sf::Vertex &_vertex);
	};
};
#endif