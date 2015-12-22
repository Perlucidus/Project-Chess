#ifndef _KING
#define _KING

#include "ChessPiece.h"
#include "Board.h"

class King : public ChessPiece {
public:
	King(const Point&, Color);
	MoveCode checkMove(const Board&, const Point&) const;
};
#endif
