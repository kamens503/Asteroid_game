#include "Player.h"

Player::Player(Palette::Color _colorA, Palette::Color _colorB, float *_dt)
{
	dt_ptr = _dt;
	body = set_shape(_colorA, _colorB);
	set_kinetic(350.f, 500.f);

	set_movement(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);

	set_position({ 1280.f / 2, 720.f / 2 });

}
void Player::set_kinetic(float _velocity, float _max_velocity)
{
	velocity = _velocity;
	max_velocity = _max_velocity;
}

Canvas::Polygon Player::set_shape(Palette::Color _colorA, Palette::Color _colorB)
{
	sf::VertexArray shape(sf::TriangleFan, 8);

	shape[0].position = sf::Vector2f(15.f, 47.f);
	shape[1].position = sf::Vector2f(0.f, 40.f);
	shape[2].position = sf::Vector2f(15.f, 23.f);
	shape[3].position = sf::Vector2f(24.f, 0.f);

	shape[4].position = sf::Vector2f(26.f, 0.f);
	shape[5].position = sf::Vector2f(35.f, 23.f);
	shape[6].position = sf::Vector2f(50.f, 40.f);
	shape[7].position = sf::Vector2f(35.f, 47.f);
	//shape[8].position = sf::Vector2f(50.f * 0.5f, 47.f * 0.5f);

	for (size_t i = 0; i < shape.getVertexCount(); i++)
	{
		_colorA.set_to(shape[i]);
	}

	_colorB.set_to(shape[3]);
	_colorB.set_to(shape[4]);
	//Size is equal to the biggest X and Y vertex position of the array
	size = { 50.f,47.f };
	position = {size.x * 0.5f, size.y * 0.5f};
	orientation = 90.f;

	sf::Transform transform;

	return { shape, transform };

}
Canvas::Render_item Player::render()
{
	Canvas::Render_item r = { &body.shape, &body.transform, true };
	return r;
}

void Player::set_movement(sf_key _up, sf_key _down, sf_key _left, sf_key _right)
{
	Component::Input_listener up_input = { _up ,[&]() {
		move({ 0.f,-1.f }); } 
	};
	Component::Input_listener down_input = { _down ,[&]() {
		move({ 0.f, 1.f }); }
	};
	Component::Input_listener left_input = { _left ,[&]() {
		move({ -1.f, 0.f }); }
	};
	Component::Input_listener right_input = { _right ,[&]() {
		move({ 1.f, 0.f }); }
	};
	inputs.push_back(up_input);
	inputs.push_back(down_input);
	inputs.push_back(right_input);
	inputs.push_back(left_input);


}

void Player::move(Util::Unit_vector _direction)
{
	float x = (velocity * _direction.x) * *dt_ptr;
	float y = (velocity * _direction.y) * *dt_ptr;

	position.x = position.x + x;
	position.y = position.y + y;

	//ship.transform.translate(sf::Vector2f(x, y));

	for (size_t i = 0; i < body.shape.getVertexCount(); i++)
	{
		body.shape[i].position.x += x;
		body.shape[i].position.y += y;

	};


	
	std::cout << "Pos X: " << position.x << std::endl;
	std::cout << "Pos Y: " << position.y << std::endl;
}

void Player::set_position(sf::Vector2f _pos)
{
	sf::Vector2f center = { size.x / 2 , size.y / 2 };
	position += _pos;
	for (size_t i = 0; i < body.shape.getVertexCount(); i++)
	{
		body.shape[i].position += _pos;
	}
}
void Player::rotate(float _angle)
{
}