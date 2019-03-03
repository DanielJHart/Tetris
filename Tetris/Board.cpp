#include "Board.h"
#include <string>
#include <SFML/Graphics.hpp>

#define tileWidth 32
#define numberOfTetrominoes 7

Board::Board()
{

}

void Board::Init()
{
	const std::string fileNames[numberOfTetrominoes]{ "Line", "S", "Z", "T", "L", "ReverseL", "Square" };

	for (int i = 0; i < numberOfTetrominoes; ++i)
	{
		bool loaded = m_Textures[i].loadFromFile("Assets/Sprites/" + fileNames[i] + ".png");
		
		if (!loaded)
		{
			return;
		}

		m_sprites[i].setTexture(m_Textures[i], true);
	}

	m_RenderTexture.create(320, 640);

	ClearBoard();
}

void Board::Update()
{

}

void Board::Render(sf::RenderWindow* renderWindow)
{
	m_RenderTexture.clear();

	for (int j = 0; j < SIZEY; ++j)
	{
		for (int i = 0; i < SIZEX; ++i)
		{
			int index = i + (j * SIZEX);
			char val = m_Board[index];

			if (val >= 0)
			{
				// Render in xOffset + (tileWidth * x), yOffset + (tileWidth * y)
				sf::Sprite sprite = m_sprites[val];
				sprite.setPosition(tileWidth * i, tileWidth * j);
				m_RenderTexture.draw(sprite);
			}
		}
	}

	m_RenderTexture.display();
	renderWindow->draw(sf::Sprite(m_RenderTexture.getTexture()));
}

void Board::ClearBoard()
{
	for (int i = 0; i < SIZEX * SIZEY; ++i)
	{
		m_Board[i] = -1;
	}
}
