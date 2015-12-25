#ifndef _CHESS_UTILITY
#define _CHESS_UTILITY

#include "Board.h"
#include "Point.h"

class Board;

class ChessUtility {
public:
	static Point parsePoint(const string&);
	static MoveCode makeMove(Board&, Color, const Point&, const Point&);
private:
	static bool isCheck(const Board&, Color);
	static bool isMate(Board&, Color);
};

#endif
