#include "Pawn.h"
#include <algorithm>

Pawn::Pawn(const Point& p, Color c) : ChessPiece(p, c, PieceType::Pawn){}

MoveCode Pawn::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;

	if (((_color == Color::Black && _position.second == 1 && destination.second - _position.second <= 2 && destination.second - _position.second > 0) ||
		(_color == Color::White && _position.second == 6 && _position.second - destination.second <= 2 && _position.second - destination.second > 0)) &&
		_position.first == destination.first && board.getPiece(destination).getColor() == Color::Transparent)
		return MoveCode::Valid;
	
	if (((_color == Color::Black && destination.second - _position.second == 1) ||
		(_color == Color::White && _position.second - destination.second == 1)) &&
		_position.first == destination.first && board.getPiece(destination).getColor() == Color::Transparent)
		return MoveCode::Valid;

	if (((_color == Color::Black && abs(_position.first - destination.first) == 1 && destination.second - _position.second == 1) ||
		(_color == Color::White && abs(_position.first - destination.first) == 1 && _position.second - destination.second == 1)) &&
		board.getPiece(destination).getColor() != _color)
	{
		if (board.getPiece(destination).getColor() != Color::Transparent ||
			(board.getPiece(Point(destination.first, _position.second)).getColor() != _color &&
			board.getPiece(Point(destination.first, _position.second)).getColor() != Color::Transparent))
			return MoveCode::Valid;
	}
		
	return MoveCode::InvalidMove;
}

bool Pawn::isPromotion(Board& board, const Point& destination)
{
	return (_color == Color::Black && destination.second == 6) || (_color == Color::White && destination.second == 1);
}