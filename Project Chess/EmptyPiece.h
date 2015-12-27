#ifndef _EMPTY_PIECE
#define _EMPTY_PIECE

#include "ChessPiece.h"
#include "ChessMove.h"

class EmptyPiece : public ChessPiece
{
public:
	EmptyPiece();

	virtual MoveCode checkMove(const Board&, const Point&) const { return MoveCode::InvalidMove; }
	virtual ChessPiece* clone() const { return new EmptyPiece(); }
	virtual void getAvailableMoves(const Board&, ChessMoves& moves) const {}
};

#endif
