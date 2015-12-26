#ifndef _PAWN
#define _PAWN

#include "ChessPiece.h"
#include "Board.h"

class Pawn : public ChessPiece
{
public:
	Pawn(const Point&, Color);

	virtual MoveCode checkMove(const Board&, const Point&) const;
	virtual ChessPiece* clone() const { return new Pawn(_position, _color); }
	virtual ChessMoves getAvailableMoves(const Board&) const;
};

#endif
