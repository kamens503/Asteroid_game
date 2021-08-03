#pragma once

#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include <string>
#include <map>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Util.h"
#include "Scene.h"
#include <iostream>
#include "Debug.h"
#include "Component.h"


class Game
{
private:
	std::string name;
	Util::Size resolution;
	Util::Dt delta_time;
	Scene* active_scene;
	//Functions
public:
	//sf::Vector2f center;
	float dt;
	sf::RenderWindow* window = nullptr;
	sf::Event* event = nullptr;
	//Functions
	Game(std::string _name,Util::Size _resolution);
	~Game();

	void update();
	void set_scene(Scene* _scene);
	void draw_layer(Scene::Layer _stack);
	void set_event();
	float time();

	void render();
};

#endif