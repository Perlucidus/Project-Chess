#include "Knight.h"

Knight::Knight(Point p, Color c)
	: ChessPiece(p, c, PieceType::Knight){}

bool Knight::canMove(Board* board, Point position)
{
	if ((_position.getX() == position.getX() - 2 || _position.getX() == position.getX() + 2) &&
		(_position.getY() == position.getY() - 1 || _position.getY() == position.getY() + 1))
		return true;
	else if ((_position.getX() == position.getX() - 1 || _position.getX() == position.getX() + 1) &&
		(_position.getY() == position.getY() - 2 || _position.getY() == position.getY() + 2))
		return true;
	
	return false;
}