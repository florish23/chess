#include <algorithm>
#include "Figure.h"

void Figure::set_name(figure_name _name)
{
	name = _name;
}

void Figure::set_pos(coord _pos)
{
	pos = _pos;
}

figure_name Figure::get_name()
{
	return name;
}

coord Figure::get_pos()
{
	return pos;
}

int Figure::find_pos(coord pos)
{
	for (int i = 0; i < available.size(); i++)
	{
		if (pos == available[i])
		{
			return i;
		}
	}
	return available.size();
}

bool Figure::check_move(coord pos)
{
	if (find_pos(pos) != available.size())
	{
		return true;
	}
	return false;
}

void Figure::update_available(figure_name * board[8])
{
	switch (name)
	{
	case WhitePawn:
		set_WhitePawn(board);
		break;
	default:
		break;
	}
}

void Figure::set_WhitePawn(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	if (board[x][y + 1] == none)
	{
		available.push_back({ x, y + 1 });
	}
	if (y == 1)
	{
		available.push_back({ x, y + 2 });
	}
	if (x == 0)
	{
		if (y != 7)
		{
			switch (board[x + 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				available.push_back({ x + 1, y + 1 });
				break;
			default:
				break;
			}
		}
	}
	else if (x == 7)
	{
		if (y != 7)
		{
			switch (board[x - 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				available.push_back({ x - 1, y + 1 });
				break;
			default:
				break;
			}
		}
	}
	else
	{
		if (y != 7)
		{
			switch (board[x + 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				available.push_back({ x + 1, y + 1 });
				break;
			default:
				break;
			}
			switch (board[x - 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				available.push_back({ x - 1, y + 1 });
				break;
			default:
				break;
			}
		}
	}
}