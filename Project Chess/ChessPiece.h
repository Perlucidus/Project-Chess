#pragma once
#include "Point.h"
#include "Definitions.h"
#include "EmptyPiece.h"
#include "Board.h"
#include "ChessUtility.h"

class EmptyPiece;
class ChessPiece
{
public:
	ChessPiece(Point, Color, PieceType);
	ChessPiece(int, int, Color, PieceType);
	~ChessPiece();

	EmptyPiece* temp(Color, Point);
	void move(Point);
	EmptyPiece* temp(Color, int, int);
	void move(int,int);

	Point* getPoint();
	void setPoint(Point);
	void setPoint(int, int);
	Color getColor();
	PieceType getType();
	void setType(PieceType);

	bool canMove(Point);

protected:
	Point* _point;
	Color _color;
	PieceType _type;
};