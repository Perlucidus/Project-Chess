#include "Bishop.h"

Bishop::Bishop(Point p, Color c) : ChessPiece(p, c, PieceType::Bishop){}

bool Bishop::canMove(Board* board, Point position)
{
	if (_position.equals(position))
		return false;
	if (abs(_position.getX() - position.getX()) == abs(_position.getY() - position.getY()))
		return true;

	return false;
}