#include "Knight.h"

Knight::Knight(const Point& p, Color c)
	: ChessPiece(p, c, PieceType::Knight) {}

MoveCode Knight::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;

	if ((abs(_position.first - destination.first) == 2 && abs(_position.second - destination.second) == 1) ||
		(abs(_position.first - destination.first) == 1 && abs(_position.second - destination.second) == 2))
		return MoveCode::Valid;
	return MoveCode::InvalidMove;
}

void Knight::getAvailableMoves(const Board& board, ChessMoves& moves) const {
	for (int x = _position.first - 1; x <= _position.first + 1; x += 2)
		for (int y = _position.second - 2; y <= _position.second + 2; y += 4) {
			if (Point(x, y).inBounds(BOARD_WIDTH, BOARD_HEIGHT) && board.getPiece(Point(x, y)).getColor() != _color)
				if (board.getPiece(Point(x, y)).getType() != PieceType::Empty)
					moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
				else
					moves.push_back(new ChessMove(*this, Point(x, _position.second + 1)));
		}

	for (int x = _position.first - 2; x <= _position.first + 2; x += 4)
		for (int y = _position.second - 1; y <= _position.second + 1; y += 2) {
			if (Point(x, y).inBounds(BOARD_WIDTH, BOARD_HEIGHT) && board.getPiece(Point(x, y)).getColor() != _color)
				if (board.getPiece(Point(x, y)).getType() != PieceType::Empty)
					moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
				else
					moves.push_back(new ChessMove(*this, Point(x, _position.second + 1)));
		}
}
