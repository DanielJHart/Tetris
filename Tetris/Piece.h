#pragma once

#include <SFML/Graphics.hpp>

class Piece
{
public:
	// Set local position
	void SetPosition(sf::Vector2f pos) { position = pos; };
	sf::Vector2f GetPosition() { return position; };
private:
	sf::Vector2f position;
};