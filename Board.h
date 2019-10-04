#pragma once
#include <string>
#include "Figure.h"

enum Color { white, black };

class Board
{
private:
	std::string b_fen;//Forsade-Edwards Notation
	Color b_move_color;//color next move
	int b_move_num;//move's number
	figure_name b_board[8][8];
	std::string b_move;
	std::vector<Figure> b_figure;
public:
	Board();
	Board(std::string fen);
	bool check_num(char str);
	void set_figure(int x, int y, int counter);
	void init_board();
	void print_board();
	void set_fen(std::string fen);
	void set_move(std::string move);
	int find_figure(coord pos);
	void move_figure();
};