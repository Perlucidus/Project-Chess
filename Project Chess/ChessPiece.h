#ifndef _CHESS_PIECE
#define _CHESS_PIECE

#include "Definitions.h"
#include "Point.h"
#include "Board.h"
#include <vector>

using namespace std;

class Board;

class ChessPiece {
public:
	ChessPiece(Point, Color, PieceType);

	Point getPosition();
	Color getColor();
	PieceType getType();
	void move(Point);

	virtual bool canMove(Board*, Point) = 0;
	vector<Point> getAvailableMoves(Board*);

protected:
	Point _position;
	Color _color;
	PieceType _type;
};

#endif
