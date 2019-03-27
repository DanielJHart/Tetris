#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	void Init(sf::RenderWindow* window);
	bool Update(float dt, sf::Event evt);
	void Render();
	void Close();
private:
	void ResetTimer();

	Board mBoard;
	float timer;
	sf::RenderWindow* m_pRenderWindow;
};