#pragma once
#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include <string>
#include "Util.h"
#include "SFML/Graphics.hpp"
#include "Palette.h"
#include "Canvas.h"
#include "Component.h"
class Scene
{
public:
	enum Layers
	{
		VIEW, UI, DEBUG
	};
	std::vector <Component::Listener*> listeners;
	typedef std::vector <Canvas::Render_item> Layer;
	Scene(std::string _name, Util::Size _res, Palette::Color _colorA, Palette::Color _colorB);
	
	Layer view;
	Layer ui;
	Layer debug;

	void set_background(Util::Size _res, Palette::Color _colorA, Palette::Color _colorB);
	void set_background(Util::Size _res, Palette::Color _colorA);
	Canvas::Polygon background;

	void add_to_layer(Canvas::Render_item _item, Layers _layer);

	void add_listener(std::vector <Component::Input_listener> &_actions);
	void add_listener(Component::Input_listener& _action);

	void add_listener(std::vector <Component::Raw_listener>& _actions);
	void add_listener(Component::Raw_listener& _action);


private:
	std::string name;
	
};
#endif
