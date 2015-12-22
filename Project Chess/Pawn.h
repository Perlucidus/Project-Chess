#ifndef _PAWN
#define _PAWN

#include "ChessPiece.h"
#include "Board.h"

class Pawn : public ChessPiece
{
public:
	Pawn(const Point&, Color);
	MoveCode checkMove(const Board&, const Point&) const;
	bool isPromotion(Board&, const Point&);
};

#endif
