#pragma once
#ifndef __COMPONENT_H_INCLUDED__
#define __COMPONENT_H_INCLUDED__
#include "SFML/Graphics.hpp"
#include "Util.h"

namespace Component
{
	class Mouse
	{
	public:
		sf::RenderWindow* window;
		sf::Vector2f pos;
		Mouse(sf::RenderWindow* _window_ptr);
		~Mouse();
		void update();

	private:

	};
	class Listener
	{


	};
	class Input_listener : public Listener
	{
	public:
		Input_listener(sf::Keyboard::Key _trigger, Util::action _action);
		sf::Keyboard::Key trigger;
		Util::action action;

		bool is_triggered();
	};

	class Raw_listener : public Listener
	{
	public:
		Raw_listener(bool &_trigger, Util::action _action);
		bool trigger;
		Util::action action;

		bool is_triggered();

	};
};

#endif