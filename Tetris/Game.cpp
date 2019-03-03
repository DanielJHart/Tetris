#include "Game.h"

#include <SFML/Window.hpp>

void Game::Init(sf::RenderWindow* window)
{
	m_pRenderWindow = window;
	mBoard.Init();
}

bool Game::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return false;
	}

	mBoard.Update();

	return true;
}

void Game::Render()
{
	mBoard.Render(m_pRenderWindow);
	m_pRenderWindow->display();
}

void Game::Close()
{
}
