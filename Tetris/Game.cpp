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
	t = Tetromino(TetrominoType::L, sf::Vector2f(5, 5));
	timer = 0;
}


bool Game::Update(float dt, sf::Event evt)
{
	static int i = 0;
	static bool Latch = false;

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return false;
	}

	if (evt.type == sf::Event::KeyPressed && !Latch)
	{
		// A key has been pressed.
		// Find what key has been pressed

		// Set the latch so no repeats
		Latch = true;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			++i;
			if (i == NUMBER_OF_TETROMINOES)
			{
				i = 0;
			}
			t = Tetromino(TetrominoType(i), sf::Vector2f(5 * TileWidth, 5 * TileWidth));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// Rotate piece right
			t.RotateRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// Move Piece Down
			t.MoveDown();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// Move Piece Right
			t.MoveRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// Move Piece Left
			t.MoveLeft();
		}
	}

	if (evt.type == sf::Event::KeyReleased && Latch)
	{
		Latch = false;
	}

	mBoard.Update();

	// If on the beat
	timer += dt;
	if (timer >= 1.0f)
	{
		ResetTimer();
		mBoard.CheckForCollision(t);
	}

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

void Game::ResetTimer()
{
	timer = 0;
}
