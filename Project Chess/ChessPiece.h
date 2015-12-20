#ifndef _CHESS_PIECE
#define _CHESS_PIECE

#include "Definitions.h"
#include "Point.h"

using namespace std;

class Board;

class ChessPiece {
public:
	ChessPiece();
	ChessPiece(const Point&, Color, PieceType);
	const Point& getPosition() const;
	Color getColor() const;
	PieceType getType() const;
	void move(const Point&);

	MoveCode checkMove(const Board&, const Point&) const throw(...);

protected:
	Point _position;
	Color _color;
	PieceType _type;

	MoveCode checkSanity(const Board&, const Point&) const;
};

#endif
