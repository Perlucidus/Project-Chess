#include "Rook.h"
#include <algorithm>

Rook::Rook(const Point& position, Color color) : ChessPiece(position, color, PieceType::Rook) {}

MoveCode Rook::checkMove(const Board& board, const Point& destination) const {
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;
	if (_position.first == destination.first) {
		for (int y = std::min(_position.second, destination.second) + 1;
		y < std::max(_position.second, destination.second); y++) {
			if (board.getPiece(Point(_position.first, y)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
		}
		return MoveCode::Valid;
	}
	if (_position.second == destination.second) {
		for (int x = std::min(_position.first, destination.first) + 1;
		x < std::max(_position.first, destination.first); x++) {
			if (board.getPiece(Point(x, _position.second)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
		}
		return MoveCode::Valid;
	}
	return MoveCode::InvalidMove;
}

void Rook::getAvailableMoves(const Board& board, ChessMoves& moves) const
{
	for (int x = _position.first + 1; x < BOARD_WIDTH; x++) {
		if (board.getPiece(Point(x, _position.second)).getColor() == _color)
			break;
		if (board.getPiece(Point(x, _position.second)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, _position.second))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(x, _position.second)));
	}
	for (int x = _position.first - 1; x > 0; x--) {
		if (board.getPiece(Point(x, _position.second)).getColor() == _color)
			break;
		if (board.getPiece(Point(x, _position.second)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, _position.second))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(x, _position.second)));
	}
	for (int y = _position.second; y < BOARD_HEIGHT; y++) {
		if (board.getPiece(Point(_position.first, y)).getColor() == _color)
			break;
		if (board.getPiece(Point(_position.first, y)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(_position.first, y))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(_position.first, y)));
	}
	for (int y = _position.second; y > 0; y--) {
		if (board.getPiece(Point(_position.first, y)).getColor() == _color)
			break;
		if (board.getPiece(Point(_position.first, y)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(_position.first, y))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(_position.first, y)));
	}
}