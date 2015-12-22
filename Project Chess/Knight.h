#ifndef _KNIGHT
#define _KNIGHT

#include "ChessPiece.h"
#include "Board.h"

class Knight : public ChessPiece
{
public:
	Knight(const Point&, Color);
	MoveCode checkMove(const Board&, const Point&) const;
};
#endif