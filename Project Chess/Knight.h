#include "ChessPiece.h"
#include "Board.h"

class Knight : public ChessPiece
{
public:
	Knight(Point, Color);
	~Knight();
	bool canMove(Board*, Point);
};