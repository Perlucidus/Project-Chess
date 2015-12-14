#include "ChessPiece.h"
#include "Board.h"
#include <vector>

class Rook : public ChessPiece {
public:
	Rook(Point, Color);
	~Rook();
	bool canMove(Board*, Point);
};
