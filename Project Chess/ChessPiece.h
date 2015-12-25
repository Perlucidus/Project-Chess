#ifndef _CHESS_PIECE
#define _CHESS_PIECE

#include "Definitions.h"
#include "Point.h"
#include <map>

class Board;
class ChessMoves;

class ChessPiece {
public:
	ChessPiece();
	ChessPiece(const Point&, Color, PieceType);
	const Point& getPosition() const;
	Color getColor() const;
	PieceType getType() const;
	void setType(PieceType);
	void move(const Point&);

	virtual ChessPiece* clone() const = 0;
	virtual MoveCode checkMove(const Board&, const Point&) const = 0;
	virtual ChessMoves getAvailableMoves(const Board&) const = 0;

protected:
	Point _position;
	Color _color;
	PieceType _type;

	MoveCode checkSanity(const Board&, const Point&) const;
};

class ChessPieces : public std::map<Point, const ChessPiece*> {
public:
	~ChessPieces();
};

#endif
