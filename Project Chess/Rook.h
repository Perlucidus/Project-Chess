#ifndef _ROOK
#define _ROOK

#include "ChessPiece.h"
#include "Board.h"

class Rook : public ChessPiece
{
public:
	Rook(const Point&, Color);

	virtual MoveCode checkMove(const Board&, const Point&) const;
	virtual ChessPiece* clone() const { return new Rook(_position, _color); }
	virtual ChessMoves getAvailableMoves(const Board&) const;
};

#endif
