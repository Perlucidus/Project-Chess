#include "ChessPiece.h"
#include "Board.h"

class Rook : public ChessPiece
{
public:
	Rook(Point, Color);
	bool canMove(Board*, Point);
};
