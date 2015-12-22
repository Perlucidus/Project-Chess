#ifndef _QUEEN
#define _QUEEN

#include "ChessPiece.h"
#include "Board.h"

class Queen : public ChessPiece
{
public:
	Queen(const Point&, Color);
	MoveCode checkMove(const Board&, const Point&) const;
};

#endif
