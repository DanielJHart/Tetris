#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Constants.h"

enum TetrominoType
{
	Line = 0,
	S = 1,
	Z = 2,
	T = 3,
	L = 4,
	ReverseL = 5,
	Square = 6
};

class Tetromino
{
public:
	Tetromino() {};
	Tetromino(TetrominoType type, sf::Vector2f pos)
	{
		// Set the local positions of each piece
		switch (type)
		{
		case Line:
			//  *
			// _*
			//  *
			//  *
			m_Texture.loadFromFile("Assets/Sprites/Line.png");
			pieces[0].SetPosition(sf::Vector2f(0, 1));
			pieces[1].SetPosition(sf::Vector2f(0, 0));
			pieces[2].SetPosition(sf::Vector2f(0, -1));
			pieces[3].SetPosition(sf::Vector2f(0, -2));
			break;
		case S:
			//   **
			//  **
			m_Texture.loadFromFile("Assets/Sprites/S.png");
			pieces[0].SetPosition(sf::Vector2f(1, 0));
			pieces[1].SetPosition(sf::Vector2f(0, 0));
			pieces[2].SetPosition(sf::Vector2f(0, -1));
			pieces[3].SetPosition(sf::Vector2f(-1, -1));
			break;
		case Z:
			//  **
			//   **
			m_Texture.loadFromFile("Assets/Sprites/Z.png");
			pieces[0].SetPosition(sf::Vector2f(-1, 0));
			pieces[1].SetPosition(sf::Vector2f(0, 0));
			pieces[2].SetPosition(sf::Vector2f(0, -1));
			pieces[3].SetPosition(sf::Vector2f(1, -1));
			break;
		case T:
			// ***
			//  *
			m_Texture.loadFromFile("Assets/Sprites/T.png");
			pieces[0].SetPosition(sf::Vector2f(-1, 0));
			pieces[1].SetPosition(sf::Vector2f(0, 0));
			pieces[2].SetPosition(sf::Vector2f(1, 0));
			pieces[3].SetPosition(sf::Vector2f(0, -1));
			break;
		case L:
			// *
			// *
			// **
			m_Texture.loadFromFile("Assets/Sprites/L.png");
			pieces[0].SetPosition(sf::Vector2f(-1, 1));
			pieces[1].SetPosition(sf::Vector2f(-1, 0));
			pieces[2].SetPosition(sf::Vector2f(-1, -1));
			pieces[3].SetPosition(sf::Vector2f(0, -1));
			break;
		case ReverseL:
			//  *
			//  *
			// **
			m_Texture.loadFromFile("Assets/Sprites/ReverseL.png");
			pieces[0].SetPosition(sf::Vector2f(0, 1));
			pieces[1].SetPosition(sf::Vector2f(0, 0));
			pieces[2].SetPosition(sf::Vector2f(0, -1));
			pieces[3].SetPosition(sf::Vector2f(-1, -1));
			break;
		case Square:

			// **
			// **
			m_Texture.loadFromFile("Assets/Sprites/Square.png");
			pieces[0].SetPosition(sf::Vector2f(-1, 0));
			pieces[1].SetPosition(sf::Vector2f(0, 0));
			pieces[2].SetPosition(sf::Vector2f(-1, -1));
			pieces[3].SetPosition(sf::Vector2f(0, -1));
			break;
		default:
			break;
		}

		m_Position = pos;
		this->type = type;
		m_Sprite = sf::Sprite(m_Texture);
		m_Sprite.setPosition(sf::Vector2f(pos));
	}

	void RotateRight()
	{
		// A square does not need rotating
		if (type != TetrominoType::Square)
		{
			rotation = (rotation + 1) % 4;
		

			for (int i = 0; i < 4; ++i)
			{
				sf::Transform t;
				t.rotate(90, sf::Vector2f(-0.5, -0.5));
				pieces[i].SetPosition(t.transformPoint(pieces[i].GetPosition()));
			}
		}


	}

	void RotateLeft()
	{
		rotation = (rotation - 1) % 4;
	}

	void Render(sf::RenderWindow* rw)
	{
		for (int i = 0; i < 4; ++i)
		{
			m_Sprite.setPosition(m_Position + (pieces[i].GetPosition() * (float)TILE_WIDTH));
			rw->draw(m_Sprite);
		}
	}

	Piece pieces[4];
	TetrominoType type;
	wchar_t rotation = 0;
private:
	sf::Vector2f m_Position;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};
