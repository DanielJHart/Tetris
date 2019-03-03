#pragma once

#include "AssetPool.h"
#include <SFML/Graphics.hpp>

constexpr char SIZEX = 10;
constexpr char SIZEY = 20;

class Board
{
public:
	Board();
	void Init();
	void Update();
	void Render(sf::RenderWindow* window);
	bool CheckForCollision();
	void ClearBoard();
private:
	char m_Board[SIZEX * SIZEY];
	sf::Texture m_Textures[7];
	sf::Sprite m_sprites[7];
	sf::RenderTexture m_RenderTexture;
};