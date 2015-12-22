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