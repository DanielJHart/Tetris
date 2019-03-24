#include "Game.h"

#include "Constants.h"
#include <SFML/Window.hpp>
#include "Tetromino.h"

constexpr int TileWidth = 32;

Tetromino t;

void Game::Init(sf::RenderWindow* window)
{
	m_pRenderWindow = window;
	mBoard.Init();
	t = Tetromino(TetrominoType::L, sf::Vector2f(5 * TileWidth, 5 * TileWidth));
}


bool Game::Update(float dt)
{
	static int i = 0;
	static bool Latch = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		// Spawn Piece
		if (!Latch)
		{
			Latch = true;
			++i;
			if (i == NUMBER_OF_TETROMINOES)
			{
				i = 0;
			}

			t = Tetromino(TetrominoType(i), sf::Vector2f(5 * TileWidth, 5 * TileWidth));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// Spawn Piece
		if (!Latch)
		{
			Latch = true;
			t.RotateRight();
		}
	}
	else if (Latch)
	{
		Latch = false;
	}

	mBoard.Update();

	return true;
}

void Game::Render()
{
	m_pRenderWindow->clear(CLEAR_COLOUR);
	mBoard.Render(m_pRenderWindow);
	t.Render(m_pRenderWindow);
	m_pRenderWindow->display();
}

void Game::Close()
{
}
