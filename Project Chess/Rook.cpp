#include "Rook.h"

Rook::Rook(Point position, Color color)
	: ChessPiece(position, color, PieceType::Rook) {}

bool Rook::canMove(Board* board, Point position)
{
	if (_position.equals(position))
		return false;
	if (_position.getX() != position.getX() &&
		_position.getY() != position.getY())
		return false;
	else if (_position.getX() != position.getX())
	{
		bool right = _position.getX() < position.getX();
		int x = _position.getX();
		do
		{
			right ? x++ : x--;
			if (board->getPiece(Point(x, position.getY()))->getType() != PieceType::Empty)
				break;
		} while (x != position.getX());
		if (x != position.getX())
			return false;
	}
	else if (_position.getY() != position.getY())
	{
		bool up = _position.getY() < position.getY();
		int y = _position.getY();
		do
		{
			up ? y++ : y--;
			if (board->getPiece(Point(position.getX(), y))->getType() != PieceType::Empty)
				break;
		} while (y != position.getY());
		if (y != position.getY())
			return false;
	}
	return true;
}
