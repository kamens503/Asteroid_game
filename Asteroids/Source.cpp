#include "Game.h"
#include "Util.h"
#include "Scene.h"
#include "Player.h"
#include "Debug.h"

void hello() {
	std::cout << "Hello World" << std::endl;
};
int main()
{
    Util::Size res = { 1280.f,720.f};
    Game game("Asteroids", res);
	Component::Mouse mouse(game.window);

	Palette::Color white = { 255,255,255,255 };
	Palette::Color tinted_white = { 213, 227, 230, 255 };
	Palette::Color pink = { 127,165,171,255 };
	Palette::Color blue = { 244,143,160,255 };

   Scene* level_1 = new Scene("Level 1",res,blue, pink);
   level_1->set_background(res, pink, blue);

   Player player(white, tinted_white, &game.dt);

   level_1->add_to_layer(player.render(), Scene::VIEW);
   level_1->add_listener(player.inputs);

   Debug::Line cursor_dist(&player.position, &mouse.pos);
   Component::Raw_listener cursor_gizmo = { Debug::Gizmo::visible,
	   [&]() { cursor_dist.update(); }
	   };
   level_1->add_listener(cursor_gizmo);

   level_1->add_to_layer(cursor_dist.render(), Scene::DEBUG);


    game.set_scene(level_1);
    while (game.window->isOpen())
    {
		//Rotate Player
		sf::Vector2i cursorPos = sf::Mouse::getPosition(*game.window);

		

		sf::Vector2f distance = { cursorPos.x - player.position.x, cursorPos.y - player.position.y };

		sf::Vector2f direction = { player.position.x / distance.x, player.position.y / distance.y };

		std::cout << "X: " << distance.x << " Y: " << distance.y << std::endl;

		/*std::cout << "Orientation: " << player.orientation - rotation << std::endl;
		std::cout << "Rotation: " << rotation<< std::endl;
		std::cout << "Distance: " << distance.x  << " " << distance.y << std::endl;
		std::cout << "Player: " << player.position.x << " " << player.position.y << std::endl;*/
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			player.body.transform.rotate(80 * game.dt);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			player.body.transform.rotate(-80 * game.dt);
		}

		


		game.update();
        game.render();
    }

    return 0;
}