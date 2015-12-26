#include "Pawn.h"
#include <algorithm>

Pawn::Pawn(const Point& p, Color c) : ChessPiece(p, c, PieceType::Pawn){}

MoveCode Pawn::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;

	if (((_color == Color::Black && _position.second == 1 && destination.second - _position.second <= 2 && destination.second - _position.second > 0
		&& board.getPiece(Point(_position.first, _position.second + 1)).getType() == PieceType::Empty)) ||
		(_color == Color::White && _position.second == 6 && _position.second - destination.second <= 2 && _position.second - destination.second > 0
		&& board.getPiece(Point(_position.first, _position.second - 1)).getType() == PieceType::Empty) &&
		(_position.first == destination.first && board.getPiece(destination).getColor() == Color::Transparent))
		return MoveCode::Valid;
	
	if (((_color == Color::Black && destination.second - _position.second == 1) ||
		(_color == Color::White && _position.second - destination.second == 1)) &&
		_position.first == destination.first && board.getPiece(destination).getColor() == Color::Transparent)
		return MoveCode::Valid;

	if (((_color == Color::Black && abs(_position.first - destination.first) == 1 && destination.second - _position.second == 1) ||
		(_color == Color::White && abs(_position.first - destination.first) == 1 && _position.second - destination.second == 1)) &&
		board.getPiece(destination).getColor() != _color)
		if (board.getPiece(destination).getColor() != Color::Transparent ||
			(board.getPiece(Point(destination.first, _position.second)).getColor() != _color &&
			board.getPiece(Point(destination.first, _position.second)).getColor() != Color::Transparent))
			return MoveCode::Valid;
	return MoveCode::InvalidMove;
}

ChessMoves Pawn::getAvailableMoves(const Board& board) const
{
	ChessMoves moves;
	int y;
	if (_color == Color::Black)
	{
		y = _position.second + 1;
		for (int x = _position.first - 1; x <= _position.first + 1; x++)
		{
			if (Point(x, y).inBounds(BOARD_WIDTH, BOARD_HEIGHT) && board.getPiece(Point(x, y)).getColor() != _color)
			{
				if (board.getPiece(Point(x, y)).getType() != PieceType::Empty && x != _position.first)
					moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
				if (board.getPiece(Point(x, y)).getType() == PieceType::Empty && x == _position.first)
					moves.push_back(new ChessMove(*this, Point(x, y)));
			}
		}
		if (_position.second == 1 &&
			board.getPiece(Point(_position.first, _position.second + 1)).getType() == PieceType::Empty &&
			board.getPiece(Point(_position.first, _position.second + 2)).getType() == PieceType::Empty)
			moves.push_back(new ChessMove(*this, Point(_position.first, _position.second + 2)));
	}
	if (_color == Color::White)
	{
		y = _position.second - 1;
		for (int x = _position.first - 1; x <= _position.first + 1; x++)
		{
			if (Point(x, y).inBounds(BOARD_WIDTH, BOARD_HEIGHT) && board.getPiece(Point(x, y)).getColor() != _color)
			{
				if (board.getPiece(Point(x, y)).getType() != PieceType::Empty && x != _position.first)
					moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
				if (board.getPiece(Point(x, y)).getType() == PieceType::Empty && x == _position.first)
					moves.push_back(new ChessMove(*this, Point(x, y)));
			}
		}
		if (_position.second == 6 &&
			board.getPiece(Point(_position.first, _position.second - 1)).getType() == PieceType::Empty &&
			board.getPiece(Point(_position.first, _position.second - 2)).getType() == PieceType::Empty)
			moves.push_back(new ChessMove(*this, Point(_position.first, _position.second - 2)));
	}
	return moves;
}