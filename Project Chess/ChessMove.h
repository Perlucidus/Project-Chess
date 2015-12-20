#ifndef _CHESS_MOVE
#define _CHESS_MOVE

#include "ChessPiece.h"
#include "Point.h"

class ChessMove {
public:
	ChessMove(const ChessPiece&, const Point&);
	virtual void doMove(Board&) const;
	virtual void undoMove(Board&) const;
private:
	ChessPiece _source;
	Point _destination;
};

class CaptureMove : public ChessMove {
public:
	CaptureMove(const ChessPiece&, const ChessPiece&);
	void undoMove(Board&) const;
private:
	ChessPiece _target;
};

#endif
