#include "ChessPiece.h"
#include "Board.h"

class King : public ChessPiece {
public:
	King(Point, Color);
	~King();
	bool canMove(Board*, Point);
};
