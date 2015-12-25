#ifndef _KING
#define _KING

#include "ChessPiece.h"
#include "Board.h"

class King : public ChessPiece {
public:
	King(const Point&, Color);

	virtual MoveCode checkMove(const Board&, const Point&) const;
	virtual ChessPiece* clone() const { return new King(_position, _color); }
	virtual ChessMoves getAvailableMoves(const Board&) const;
};
#endif
