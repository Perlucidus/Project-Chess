#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(Point position)
	: ChessPiece(position, Color::Transparent, PieceType::Empty) {}

bool EmptyPiece::canMove(Board*, Point) {
	return false;
}
