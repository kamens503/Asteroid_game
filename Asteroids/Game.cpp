#include "Game.h"


Game::Game(std::string _name, Util::Size _resolution) : name{ _name }, resolution{_resolution}
{
	window = new sf::RenderWindow(sf::VideoMode((unsigned int)_resolution.width, (unsigned int)_resolution.height), _name);
	event = new sf::Event();

}

Game::~Game()
{
	delete window;
	delete event;
}

void Game::render() {
	auto& window = *this->window;
	auto& event = *this->event;
	window.clear();

	draw_layer(active_scene->view);
	//draw_layer(active_scene->ui);
	draw_layer(active_scene->debug);


	window.display();
}

void Game::update() {
	auto& window = *this->window;
	auto& event = *this->event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	for (auto& listener : active_scene->listeners)
	{
		if ((*listener).is_triggered()) {
			(*listener).action();
		}
	}
	//std::cout << delta_time.time << std::endl;
	Debug::Manager::update_gizmos();
	dt = delta_time.update();
}

void Game::set_scene(Scene* _scene)
{
	active_scene = _scene;
}

void Game::draw_layer(Scene::Layer _stack)
{
	for (auto render_item : _stack)
	{
		if (render_item.has_tranform)
		{
			window->draw(*render_item.drawable, *render_item.transform);
		}
		else
		{
			window->draw(*render_item.drawable);
		}

	}
}

void Game::set_event()
{
}

float Game::time()
{
	return delta_time.time;
}


