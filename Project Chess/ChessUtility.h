#include "Board.h"
#include "Point.h"

class Board;

class ChessUtility {
public:
	static Point parsePoint(string);
	static MoveCode makeMove(Board*, Color, Point, Point);
private:
	bool isCheckMove(Board*, Color, Point, Point);
	bool isCheck(Board*, Color);
	bool isMate(Board*, Color);
};
