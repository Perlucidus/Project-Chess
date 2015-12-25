#include "Rook.h"
#include <algorithm>

Rook::Rook(const Point& position, Color color) : ChessPiece(position, color, PieceType::Rook) {}

MoveCode Rook::checkMove(const Board& board, const Point& destination) const {
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;
	if (_position.first == destination.first) {
		for (int y = std::min(_position.second, destination.second) + 1;
		y < std::max(_position.second, destination.second) - 1; y++) {
			if (board.getPiece(Point(_position.first, y)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
		}
		return MoveCode::Valid;
	}
	if (_position.second == destination.second) {
		for (int x = std::min(_position.first, destination.first) + 1;
		x < std::max(_position.first, destination.first) - 1; x++) {
			if (board.getPiece(Point(x, _position.second)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
		}
		return MoveCode::Valid;
	}
	return MoveCode::InvalidMove;
}
