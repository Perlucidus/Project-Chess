#include "ChessPiece.h"

class EmptyPiece : public ChessPiece {
public:
	EmptyPiece(Point);

	bool canMove(Board*, Point);
};
