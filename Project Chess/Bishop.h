#include "ChessPiece.h"
#include "Board.h"

class Bishop : public ChessPiece
{
public:
	Bishop(Point, Color);
	bool canMove(Board*, Point);
};