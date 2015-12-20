#ifndef _ROOK
#define _ROOK

#include "ChessPiece.h"
#include "Board.h"

class Rook : public ChessPiece
{
public:
	Rook(const Point&, Color);
	MoveCode checkMove(const Board&, const Point&) const;
};

#endif
