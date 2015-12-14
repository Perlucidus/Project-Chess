#include "ChessPiece.h"

ChessPiece::ChessPiece(Point point, Color color, PieceType type)
{
	_point = &point;
	_color = color;
	_type = type;
}

ChessPiece::ChessPiece(int x, int y, Color color, PieceType type)
{
	_point->setX(x);
	_point->setY(y);
	_color = color;
	_type = type;
}

ChessPiece::~ChessPiece(){}

EmptyPiece* ChessPiece::temp(Color c, Point p)
{
	EmptyPiece e(c, p);
	return &e;
}

void ChessPiece::move(Point p)
{
	EmptyPiece* moved_from = temp(_color, p);
	setPoint(p);
}

EmptyPiece* ChessPiece::temp(Color c, int x, int y)
{
	EmptyPiece e(c, x, y);
	return &e;
}

void ChessPiece::move(int x, int y)
{
	EmptyPiece* moved_from = temp(_color, x, y);
	setPoint(x, y);
}

Point* ChessPiece::getPoint()
{
	return _point;
}

void ChessPiece::setPoint(Point p)
{
	_point = &p;
}

void ChessPiece::setPoint(int x, int y)
{
	_point->setX(x);
	_point->setY(y);
}

Color ChessPiece::getColor()
{
	return _color;
}

void ChessPiece::setType(PieceType type)
{
	_type = type;
}

bool ChessPiece::canMove(Point point)
{

}