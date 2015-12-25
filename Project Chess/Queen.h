#ifndef _QUEEN
#define _QUEEN

#include "ChessPiece.h"
#include "Board.h"

class Queen : public ChessPiece
{
public:
	Queen(const Point&, Color);

	virtual MoveCode checkMove(const Board&, const Point&) const;
	virtual ChessPiece* clone() const { return new Queen(_position, _color); }
	virtual ChessMoves getAvailableMoves(const Board&) const;
};

#endif
