#include "Entities.h"

using namespace Entities;

typedef std::vector <std::pair<unsigned int, Entity*>> typelist;

unsigned int Manager::entities_i = 0;
typelist Manager::scenes;
typelist Manager::entities;
float Drawable::scale = 1.f;
unsigned int Scene::scenes_i = 0;

unsigned int Entities::Entity::get_local_id()
{
	return local_id;
}

unsigned int Entities::Entity::get_global_id()
{
	return unique_id;
}

void Entities::Manager::record(typelist _list, Entity* _entity)
{
	entities_i++;
	entities.push_back({ entities_i, _entity });
	_list.push_back({ (*_entity).get_local_id(), _entity });
}

void Entities::Manager::forget(typelist _list,unsigned int _unique_id, unsigned int _local_id)
{
	entities.erase(entities.begin() + _unique_id);
	_list.erase(entities.begin() + _local_id);
}



Entities::Scene::Scene(std::string _name)
{
	scenes_i++;
	local_id = scenes_i;
	Manager::record(Manager::scenes,(Entity*)this);
	layers.push_back(background);
	layers.push_back(foreground);
	layers.push_back(ui);
	layers.push_back(menu);
}


void Entities::Scene::add_to_layer(sf::Drawable* _ptr, Layer _layer)
{
	switch (_layer)
	{
	case Entities::Scene::BACKGROUND:
		background.push_back(_ptr);
		break;
	case Entities::Scene::FOREGROUND:
		foreground.push_back(_ptr);
		break;
	case Entities::Scene::UI:
		ui.push_back(_ptr);
		break;
	case Entities::Scene::MENU:
		menu.push_back(_ptr);
		break;
	default:
		throw "Invalid Layer";
		break;
	}
}


