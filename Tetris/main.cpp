#include "Game.h"
#include <SFML/Window.hpp>


int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(320, 640), "Tetris");
	sf::Event evt;
	Game game;
	game.Init(&window);

	bool isRunning = true;
	while (isRunning)
	{
		if (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
			{
				isRunning = false;
				continue;
			}
		}

		isRunning = game.Update(0.16f);
		game.Render();
	}

	game.Close();
	window.close();
	return 0;
}