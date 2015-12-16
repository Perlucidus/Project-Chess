#include "ChessPiece.h"
#include "Board.h"

class Bishop : public ChessPiece
{
public:
	Bishop(Point, Color);
	~Bishop();
	bool canMove(Board*, Point);
};