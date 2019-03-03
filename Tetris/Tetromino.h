#pragma once

class Tetromino
{
public:
	Tetromino(TetrominoType type)
	{
		switch (type)
		{
		case Line:
			m_piece[1] = 1;
			m_piece[5] = 1;
			m_piece[9] = 1;
			m_piece[13] = 1;
			break;
		case S:
			m_piece[5] = 1;
			m_piece[6] = 1;
			m_piece[8] = 1;
			m_piece[9] = 1;
			break;
		case Z:
			m_piece[4] = 1;
			m_piece[5] = 1;
			m_piece[9] = 1;
			m_piece[10] = 1;
			break;
		case T:
			m_piece[4] = 1;
			m_piece[5] = 1;
			m_piece[6] = 1;
			m_piece[9] = 1;
			break;
		case L:
			m_piece[1] = 1;
			m_piece[5] = 1;
			m_piece[9] = 1;
			m_piece[10] = 1;
			break;
		case ReverseL:
			m_piece[2] = 1;
			m_piece[6] = 1;
			m_piece[9] = 1;
			m_piece[10] = 1;
			break;
		case Square:
			m_piece[5] = 1;
			m_piece[6] = 1;
			m_piece[9] = 1;
			m_piece[10] = 1;
			break;
		default:
			break;
		}
	}
	bool m_piece[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	wchar_t rotation = 0;

};

enum TetrominoType
{
	Line,
	S,
	Z,
	T,
	L,
	ReverseL,
	Square	
};