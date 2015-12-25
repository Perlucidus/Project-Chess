#ifndef _KNIGHT
#define _KNIGHT

#include "ChessPiece.h"
#include "Board.h"

class Knight : public ChessPiece
{
public:
	Knight(const Point&, Color);

	virtual MoveCode checkMove(const Board&, const Point&) const;
	virtual ChessPiece* clone() const { return new Knight(_position, _color); }
	virtual ChessMoves getAvailableMoves(const Board&) const;
};
#endif