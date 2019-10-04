#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

int main()
{
	string fen = "ppppkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	Board B(fen);
	B.print_board();
	cin.get();
	return 0;
}