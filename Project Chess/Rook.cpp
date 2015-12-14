#include "Rook.h"

Rook::Rook(Point p, Color c) : ChessPiece(p, c, PieceType::Rook){}

Rook::~Rook(){}

vector<Point> Rook::getAvaliableMoves(Board* board)
{
	vector<Point> moves;
	int x, y;
	bool flag = false;
	for (y = _point->getY() + 1; y < BOARD_HEIGHT && !flag; y++)
	{
		if (board->getPiece(_point->getX(), y)->getColor() != _color)
		{
			if (board->getPiece(_point->getX(), y)->getColor() != Color::Transparent)
				flag = true;
			Point p(_point->getX(), y);
			moves.push_back(p);
		}
		else
			flag = true;
	}
	flag = false;
	for (y = _point->getY() - 1; y > BOARD_HEIGHT && !flag; y--)
	{
		if (board->getPiece(_point->getX(), y)->getColor() != _color)
		{
			if (board->getPiece(_point->getX(), y)->getColor() != Color::Transparent)
				flag = true;
			Point p(_point->getX(), y);
			moves.push_back(p);
		}
		else
			flag = true;
	}

	flag = false;
	for (x = _point->getX() + 1; x < BOARD_WIDTH && !flag; x++)
	{
		if (board->getPiece(x ,_point->getY())->getColor() != _color)
		{
			if (board->getPiece(x, _point->getY())->getColor() != Color::Transparent)
				flag = true;
			Point p(x, _point->getY());
			moves.push_back(p);
		}
		else
			flag = true;
	}
	flag = false;
	for (x = _point->getX() - 1; x > BOARD_WIDTH && !flag; x--)
	{
		if (board->getPiece(x, _point->getY())->getColor() != _color)
		{
			if (board->getPiece(_point->getX(), y)->getColor() != Color::Transparent)
				flag = true;
			Point p(x, _point->getY());
			moves.push_back(p);
		}
		else
			flag = true;
	}

	return moves;
}