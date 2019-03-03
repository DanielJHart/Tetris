#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	void Init(sf::RenderWindow* window);
	bool Update(float dt);
	void Render();
	void Close();
private:
	Board mBoard;
	sf::RenderWindow* m_pRenderWindow;
};