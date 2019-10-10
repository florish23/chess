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
	else if (find_pos(pos) != hit_move.size())
	{
		return true;
	}
	return false;
}

void Figure::update_available(figure_name * board[8])
{
	available.clear();
	hit_move.clear();
	switch (name)
	{
	case WhiteKing:
		set_WhiteKing(board);
		break;
	case WhiteQueen:
		set_WhiteQueen(board);
		break;
	case WhiteRook:
		set_WhiteRook(board);
		break;
	case WhiteBishop:
		set_WhiteBishop(board);
		break;
	case WhiteKnight:
		set_WhiteKnight(board);
		break;
	case WhitePawn:
		set_WhitePawn(board);
		break;
	case BlackKing:
		set_BlackKing(board);
		break;
	case BlackQueen:
		set_BlackQueen(board);
		break;
	case BlackRook:
		set_BlackRook(board);
		break;
	case BlackBishop:
		set_BlackBishop(board);
		break;
	case BlackKnight:
		set_BlackKnight(board);
		break;
	case BlackPawn:
		set_BlackPawn(board);
		break;
	default:
		break;
	}
}

void Figure::switch_white(figure_name* board[8], int x, int y)
{
	switch (board[x][y])
	{
	case none:
	case WhiteKing:
	case WhiteQueen:
	case WhiteRook:
	case WhiteBishop:
	case WhiteKnight:
	case WhitePawn:
		available.push_back({ x, y });
		break;
	default:
		break;
	}
}

void Figure::switch_black(figure_name* board[8], int x, int y)
{
	switch (board[x][y])
	{
	case none:
	case BlackKing:
	case BlackQueen:
	case BlackRook:
	case BlackBishop:
	case BlackKnight:
	case BlackPawn:
		available.push_back({ x, y });
		break;
	default:
		break;
	}
}

void Figure::set_WhiteKing(figure_name* board[8])
{

}

void Figure::set_WhiteQueen(figure_name* board[8])
{
	set_WhiteBishop(board);
	set_WhiteRook(board);
}

void Figure::set_WhiteRook(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	for (int i = x - 1; i >= 0; i--)
	{
		switch_black(board, i, y);
		if (board[i][y] != none)
		{
			break;
		}
	}
	for (int i = x + 1; i < 8; i++)
	{
		switch_black(board, i, y);
		if (board[i][y] != none)
		{
			break;
		}
	}
	for (int i = y - 1; i >= 0; i--)
	{
		switch_black(board, x, i); 
		if (board[x][i] != none)
		{
			break;
		}
	}
	for (int i = y + 1; i < 8; i++)
	{
		switch_black(board, x, i);
		if (board[x][i] != none)
		{
			break;
		}
	}
}

void Figure::set_WhiteBishop(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	for (int i = 1; i < 8; i++)
	{
		switch_black(board, x - i, y - i);
		if (board[x - i][y - i] != none)
		{
			break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		switch_black(board, x + i, y - i);
		if (board[x + i][y - i] != none)
		{
			break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		switch_black(board, x - i, y + i);
		if (board[x - i][y + i] != none)
		{
			break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		switch_black(board, x + i, y + i);
		if (board[x + i][y + i] != none)
		{
			break;
		}
	}
}

void Figure::set_WhiteKnight(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	if (x != 7)
	{
		if (x != 6)
		{
			if (y != 7)
			{
				//available.push_back({ x + 2, y + 1 });//2
				switch_black(board, x + 2, y + 1);
				if (y != 0)
				{
					//available.push_back({ x + 2, y - 1 });//3
					switch_black(board, x + 2, y - 1);
				}
			}
			else 
			{
				//available.push_back({ x + 2, y - 1 });//3
				switch_black(board, x + 2, y - 1);
			}
		}
		else if (y < 6)
		{
			//available.push_back({ x + 1, y + 2 });//1
			switch_black(board, x + 1, y + 2);
			if (y > 1)
			{
				//available.push_back({ x + 1, y - 2 });//4
				switch_black(board, x + 1, y - 2);
			}
		}
		else
		{
			//available.push_back({ x + 1, y - 2 });//4
			switch_black(board, x + 1, y - 2);
		}
	}
	if (x != 0)
	{
		if (x != 1)
		{
			if (y != 7)
			{
				//available.push_back({ x - 2, y + 1 });//7
				switch_black(board, x - 2, y + 1);
				if (y != 0)
				{
					//available.push_back({ x - 2, y - 1 });//6
					switch_black(board, x - 2, y - 1);
				}
			}
			else
			{
				//available.push_back({ x - 2, y - 1 });//6
				switch_black(board, x - 2, y - 1);
			}
		}
		else if (y < 6)
		{
			//available.push_back({ x - 1, y + 2 });//8
			switch_black(board, x - 1, y + 2);
			if (y > 1)
			{
				//available.push_back({ x - 1, y - 2 });//5
				switch_black(board, x - 1, y - 2);
			}
		}
		else
		{
			//available.push_back({ x - 1, y - 2 });//5
			switch_black(board, x - 1, y - 2);
		}
	}
}

void Figure::set_WhitePawn(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	int bit = 2 ^ (pos.x + 8 * pos.y);
	if (y == 7)
	{
		//transformation Pawn
	}
	else
	{
		if (board[x][y + 1] == none)
		{
			available.push_back({ x, y + 1 });
			if (y == 1 && board[x][y + 2] == none)
			{
				available.push_back({ x, y + 2 });
			}
		}
		if (x == 0)
		{
			switch (board[x + 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				hit_move.push_back({ x + 1, y + 1 });
				break;
			default:
				break;
			}
		}
		else if (x == 7)
		{
			switch (board[x - 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				hit_move.push_back({ x - 1, y + 1 });
				break;
			default:
				break;
			}
		}
		else
		{
			switch (board[x + 1][y + 1])
			{
			case BlackQueen:
			case BlackRook:
			case BlackBishop:
			case BlackKnight:
			case BlackPawn:
				hit_move.push_back({ x + 1, y + 1 });
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
				hit_move.push_back({ x - 1, y + 1 });
				break;
			default:
				break;
			}
		}
	}	
}

void Figure::set_BlackKing(figure_name* board[8])
{

}

void Figure::set_BlackQueen(figure_name* board[8])
{
	set_BlackBishop(board);
	set_BlackRook(board);
}

void Figure::set_BlackRook(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	for (int i = x - 1; i >= 0; i--)
	{
		switch_white(board, i, y);
		if (board[i][y] != none)
		{
			break;
		}
	}
	for (int i = x + 1; i < 8; i++)
	{
		switch_white(board, i, y);
		if (board[i][y] != none)
		{
			break;
		}
	}
	for (int i = y - 1; i >= 0; i--)
	{
		switch_white(board, x, i);
		if (board[x][i] != none)
		{
			break;
		}
	}
	for (int i = y + 1; i < 8; i++)
	{
		switch_white(board, x, i);
		if (board[x][i] != none)
		{
			break;
		}
	}
}

void Figure::set_BlackBishop(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	for (int i = 1; i < 8; i++)
	{
		switch_white(board, x - i, y - i);
		if (board[x - i][y - i] != none)
		{
			break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		switch_white(board, x + i, y - i);
		if (board[x + i][y - i] != none)
		{
			break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		switch_white(board, x - i, y + i);
		if (board[x - i][y + i] != none)
		{
			break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		switch_white(board, x + i, y + i);
		if (board[x + i][y + i] != none)
		{
			break;
		}
	}
}

void Figure::set_BlackKnight(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	if (x != 7)
	{
		if (x != 6)
		{
			if (y != 7)
			{
				//available.push_back({ x + 2, y + 1 });//2
				switch_white(board, x + 2, y + 1);
				if (y != 0)
				{
					//available.push_back({ x + 2, y - 1 });//3
					switch_white(board, x + 2, y - 1);
				}
			}
			else
			{
				//available.push_back({ x + 2, y - 1 });//3
				switch_white(board, x + 2, y - 1);
			}
		}
		else if (y < 6)
		{
			//available.push_back({ x + 1, y + 2 });//1
			switch_white(board, x + 1, y + 2);
			if (y > 1)
			{
				//available.push_back({ x + 1, y - 2 });//4
				switch_white(board, x + 1, y - 2);
			}
		}
		else
		{
			//available.push_back({ x + 1, y - 2 });//4
			switch_white(board, x + 1, y - 2);
		}
	}
	if (x != 0)
	{
		if (x != 1)
		{
			if (y != 7)
			{
				//available.push_back({ x - 2, y + 1 });//7
				switch_white(board, x - 2, y + 1);
				if (y != 0)
				{
					//available.push_back({ x - 2, y - 1 });//6
					switch_white(board, x - 2, y - 1);
				}
			}
			else
			{
				//available.push_back({ x - 2, y - 1 });//6
				switch_white(board, x - 2, y - 1);
			}
		}
		else if (y < 6)
		{
			//available.push_back({ x - 1, y + 2 });//8
			switch_white(board, x - 1, y + 2);
			if (y > 1)
			{
				//available.push_back({ x - 1, y - 2 });//5
				switch_white(board, x - 1, y - 2);
			}
		}
		else
		{
			//available.push_back({ x - 1, y - 2 });//5
			switch_white(board, x - 1, y - 2);
		}
	}
}

void Figure::set_BlackPawn(figure_name* board[8])
{
	int x = pos.x, y = pos.y;
	if (y == 0)
	{
		//transformation Pawn
	}
	else
	{
		if (board[x][y - 1] == none)
		{
			available.push_back({ x, y - 1 });
			if (y == 6 && board[x][y - 2] == none)
			{
				available.push_back({ x, y - 2 });
			}
		}
		if (x == 0)
		{
			switch (board[x + 1][y - 1])
			{
			case WhiteQueen:
			case WhiteRook:
			case WhiteBishop:
			case WhiteKnight:
			case WhitePawn:
				hit_move.push_back({ x + 1, y - 1 });
				break;
			default:
				break;
			}
		}
		else if (x == 7)
		{
			switch (board[x - 1][y - 1])
			{
			case WhiteQueen:
			case WhiteRook:
			case WhiteBishop:
			case WhiteKnight:
			case WhitePawn:
				hit_move.push_back({ x - 1, y - 1 });
				break;
			default:
				break;
			}
		}
		else
		{
			switch (board[x + 1][y - 1])
			{
			case WhiteQueen:
			case WhiteRook:
			case WhiteBishop:
			case WhiteKnight:
			case WhitePawn:
				hit_move.push_back({ x + 1, y - 1 });
				break;
			default:
				break;
			}
			switch (board[x - 1][y - 1])
			{
			case WhiteQueen:
			case WhiteRook:
			case WhiteBishop:
			case WhiteKnight:
			case WhitePawn:
				hit_move.push_back({ x - 1, y - 1 });
				break;
			default:
				break;
			}
		}
	}
}
