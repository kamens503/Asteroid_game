#include "Palette.h"

void Palette::Color::set_to(sf::Vertex &_vertex)
{
	_vertex.color = { r,g,b,a };

	std::cout << "R " <<(int) _vertex.color.r << std::endl;

}