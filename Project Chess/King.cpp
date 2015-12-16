#include "King.h"

King::King(Point position, Color color)
	: ChessPiece(position, color, PieceType::King) {}

bool King::canMove(Board* board, Point position)
{
	if (_position.equals(position))
		return false;

	if (position.getX() == _position.getX() - 1)
		if (position.getY() == _position.getY() - 1 || position.getY() == _position.getY() + 1 || position.getY() == _position.getY())
			if (board->getPiece(position)->getColor() != _color)
				return true;

	if (position.getX() == _position.getX())
		if (position.getY() == _position.getY() - 1 || position.getY() == _position.getY() + 1)
			if (board->getPiece(position)->getColor() != _color)
				return true;

	if (position.getX() == _position.getX() + 1)
		if (position.getY() == _position.getY() - 1 || position.getY() == _position.getY() + 1 || position.getY() == _position.getY())
			if (board->getPiece(position)->getColor() != _color)
				return true;	

	return false;
}
