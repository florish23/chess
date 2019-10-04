#include <iostream>
#include "Board.h"

Board::Board()
{
	b_move_color = white;
	b_move_num = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			b_board[i][j] = none;
		}
	}
}

Board::Board(std::string fen) : b_fen(fen)
{
	init_board();
}

inline bool Board::check_num(char str)
{
	if (str > '0' && str < '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline void Board::set_figure(int x, int y, int counter)
{
	switch (b_fen[counter])
	{
	case 'r':
		b_board[x][y] = BlackRook;
		break;
	case 'b':
		b_board[x][y] = BlackBishop;
		break;
	case 'n':
		b_board[x][y] = BlackKnight;
		break;
	case 'q':
		b_board[x][y] = BlackQueen;
		break;
	case 'k':
		b_board[x][y] = BlackKing;
		break;
	case 'p':
		b_board[x][y] = BlackPawn;
		break;
	case 'R':
		b_board[x][y] = WhiteRook;
		break;
	case 'B':
		b_board[x][y] = WhiteBishop;
		break;
	case 'N':
		b_board[x][y] = WhiteKnight;
		break;
	case 'Q':
		b_board[x][y] = WhiteQueen;
		break;
	case 'K':
		b_board[x][y] = WhiteKing;
		break;
	case 'P':
		b_board[x][y] = WhitePawn;
		break;
	default:
		break;
	}
}

void Board::init_board()
{
	int c = 0;//counter
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (check_num(b_fen[c]))
			{
				int temp = b_fen[c] - 48;
				for (int k = 0; k < temp; k++)
				{
					b_board[i][j] = none;
					j++;
				}
			}
			else
			{
				set_figure(i, j, c);
			}
			c++;
		}
		c++;
	}
	b_move_color = (b_fen[c] == 'w') ? Color::white : Color::black;//set move's color
	b_move_num = b_fen[b_fen.size() - 1] - 48;
}

void Board::print_board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << static_cast<char>(b_board[i][j]);
		}
		std::cout << std::endl;
	}
}

void Board::set_fen(std::string fen)
{
	b_fen = fen;
}

void Board::set_move(std::string move)
{
	b_move = move;
}

int Board::find_figure(coord pos)
{
	for (int i = 0; i < b_figure.size(); i++)
	{
		if (pos == b_figure[i].get_pos())
		{
			return i;
		}
	}
	return b_figure.size();
}

void Board::move_figure()//pe2-e4
{
	coord c_beg(b_move[1] - 97, b_move[2] - 49);
	coord c_end(b_move[4] - 97, b_move[5] - 49);
	int c = find_figure(c_beg);
	if (c != b_figure.size())
	{
		if (b_figure[c].check_move(c_end))
		{
			b_board[c_beg.x][c_beg.y] = none;
			b_board[c_end.x][c_end.y] = b_figure[c].get_name();
			b_figure[c].set_pos(c_end);
			b_figure[c].update_available();
		}
	}
}
