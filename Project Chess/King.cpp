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
