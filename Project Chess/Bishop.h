#ifndef _BISHOP
#define _BISHOP

#include "ChessPiece.h"
#include "Board.h"

class Bishop : public ChessPiece
{
public:
	Bishop(const Point&, Color);
	MoveCode checkMove(const Board&, const Point&) const;
};

#endif