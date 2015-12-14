#include "ChessPiece.h"

ChessPiece::ChessPiece(Point position, Color color, PieceType type)
	: _position(position), _color(color), _type(type) {}

Point ChessPiece::getPosition() {
	return _position;
}

Color ChessPiece::getColor() {
	return _color;
}

PieceType ChessPiece::getType() {
	return _type;
}

void ChessPiece::move(Point position) {
	_position.move(position);
}

vector<Point> ChessPiece::getAvailableMoves(Board* board) {
	vector<Point> moves;
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (canMove(board, Point(x, y)))
				moves.push_back(Point(x, y));
	return moves;
}
