#include "King.h"

King::King(const Point& position, Color color)
	: ChessPiece(position, color, PieceType::King) {}

MoveCode King::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;

	if (abs(_position.first - destination.first) <= 1 &&
		abs(_position.second - destination.second) <= 1 &&
		board.getPiece(destination).getColor() != _color)
			return MoveCode::Valid;
	return MoveCode::InvalidMove;
}

void King::getAvailableMoves(const Board& board, ChessMoves& moves) const
{
	for (int x = _position.first - 1; x <= _position.first + 1; x++)
		for (int y = _position.second - 1; y <= _position.second + 1; y++)
		{
			if (Point(x, y).inBounds(BOARD_WIDTH, BOARD_HEIGHT) && board.getPiece(Point(x, y)).getColor() != _color)
				if (board.getPiece(Point(x,y)).getType() != PieceType::Empty)
					moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
				else
					moves.push_back(new ChessMove(*this, Point(x, y)));
		}
}