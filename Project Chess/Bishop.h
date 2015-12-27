#ifndef _BISHOP
#define _BISHOP

#include "ChessPiece.h"
#include "Board.h"

class Bishop : public ChessPiece
{
public:
	Bishop(const Point&, Color);

	virtual MoveCode checkMove(const Board&, const Point&) const;
	virtual ChessPiece* clone() const { return new Bishop(_position, _color); }
	virtual void getAvailableMoves(const Board&, ChessMoves& moves) const;
};

#endif