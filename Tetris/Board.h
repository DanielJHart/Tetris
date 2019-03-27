#pragma once

#include "AssetPool.h"
#include <SFML/Graphics.hpp>
#include "Tetromino.h"

constexpr int SIZEX = 10;
constexpr int SIZEY = 20;

class Board
{
public:
	Board();
	void Init();
	void Update();
	void Render(sf::RenderWindow* window);
	bool CheckForCollision(Tetromino t);
	void ClearBoard();
private:
	char m_Board[SIZEX * SIZEY];
	sf::Texture m_Textures[7];
	sf::Texture m_GridTexture;
	sf::Sprite m_sprites[7];
	sf::Sprite m_GridSprite;
	sf::RenderTexture m_RenderTexture;
};