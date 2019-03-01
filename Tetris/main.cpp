#include "Game.h"

int main(int argc, char **argv)
{
	Game game;
	game.Init();

	bool isRunning = true;
	while (isRunning)
	{
		isRunning = game.Update(0.16f);
		game.Render();
	}

	game.Close();

	return 0;
}