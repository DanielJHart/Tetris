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

		m_GridPosition = pos;
		m_RenderPosition = pos * (float)TILE_WIDTH;
		this->type = type;
		m_Sprite = sf::Sprite(m_Texture);
		m_Sprite.setTexture(m_Texture);
		m_Sprite.setPosition(sf::Vector2f(pos));
	}

	// Rotate tetronimo right
	void RotateRight()
	{
		Rotate(90);
	}

	// Rotate tetronimo left
	void RotateLeft()
	{
		Rotate(-90);
	}

	// Move tetronimo down 1 tile
	void MoveDown()
	{
		Move(sf::Vector2f(0, 1));
	}

	// Move tetronimo left 1 tile
	void MoveLeft()
	{
		Move(sf::Vector2f(-1, 0));
	}

	// Move tetronimo right 1 tile
	void MoveRight()
	{
		Move(sf::Vector2f(1, 0));
	}

	// Returns the positions of the 4 pieces. Vecs must be an array of size 4.
	void GetPositions(sf::Vector2f *vecs)
	{
		// Assume that vecs is an array of size 4.
		for (int i = 0; i < 4; ++i)
		{
			vecs[i] = m_GridPosition + pieces[i].GetPosition();
		}
	}

	void Render(sf::RenderWindow* rw)
	{
		for (int i = 0; i < 4; ++i)
		{
			m_Sprite.setPosition(m_RenderPosition + (pieces[i].GetPosition() * (float)TILE_WIDTH));
			rw->draw(m_Sprite);
		}
	}

	Piece pieces[4];
	TetrominoType type;
	wchar_t rotation = 0;
private:
	// Move the piece in a given direction
	void Move(sf::Vector2f dir)
	{
		m_GridPosition += dir;
		m_RenderPosition += sf::Vector2f(dir.x * TILE_WIDTH, dir.y * TILE_WIDTH);
	}

	void Rotate(float angle)
	{
		// A square does not need rotating
		if (type != TetrominoType::Square)
		{
			sf::Transform t;
			t.rotate(angle, sf::Vector2f(-0.5, -0.5));

#pragma omp parallel for
			for (int i = 0; i < 4; ++i)
			{
				pieces[i].SetPosition(t.transformPoint(pieces[i].GetPosition()));
			}
		}
	}
	sf::Vector2f m_RenderPosition, m_GridPosition;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};
