#include "Component.h"

using namespace Component;

Mouse::Mouse(sf::RenderWindow* _window_ptr)
{
	window = _window_ptr;
	pos = (sf::Vector2f)sf::Mouse::getPosition(*_window_ptr);
}

Mouse::~Mouse()
{
}

void Component::Mouse::update()
{
	pos = (sf::Vector2f)sf::Mouse::getPosition(*window);
}


Component::Input_listener::Input_listener(sf::Keyboard::Key _trigger, Util::action _action)
{
	trigger = _trigger;
	action = _action;

}

bool Component::Input_listener::is_triggered()
{
	return sf::Keyboard::isKeyPressed(trigger);
}

Component::Raw_listener::Raw_listener(bool &_trigger, Util::action _action)
{
	trigger = &_trigger;
	action = _action;
}

bool Component::Raw_listener::is_triggered()
{
	return trigger;
}
