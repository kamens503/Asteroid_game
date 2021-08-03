#pragma once
#include <queue>
#include "Util.h"


namespace Entities {

	class Entity
	{
	public:
		unsigned int get_local_id();
		unsigned int get_global_id();
	protected:
	unsigned int unique_id;
	unsigned int local_id;
	};

	class Manager 
	{
	
	public:
		typedef std::vector <std::pair<unsigned int, Entity*>> typelist;
		static void record(typelist _list, Entity* _entity);
		static void forget(typelist _list, unsigned int _unique_id, unsigned int _local_id);

		static typelist entities;
		static typelist scenes;
		static unsigned int entities_i;
	};



	class Drawable : public Entity
	{
	protected:
		sf::Vector2f pos,
					 size;
		sf::Color color;

	public:
		static float scale;
	};



	class Scene : public Entity
	{
	public:
		static unsigned int scenes_i;
		typedef std::vector<sf::Drawable*> entities_list;
		enum Layer
		{
			BACKGROUND, FOREGROUND, UI, MENU
		};
		entities_list	background, 
						foreground, 
						ui, 
						menu;

		std::vector<entities_list> layers;

		std::string name;
		Scene(std::string _name);
		void add_to_layer(sf::Drawable* _ptr,Layer _layer);

	private:

	};
}


