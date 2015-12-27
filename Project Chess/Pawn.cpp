#include "Pawn.h"
#include <algorithm>

Pawn::Pawn(const Point& p, Color c) : ChessPiece(p, c, PieceType::Pawn){}

MoveCode Pawn::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;
	if (_position.first == destination.first &&
		board.getPiece(destination).getType() == PieceType::Empty) {
		if (_color == Color::White) {
			if (_position.second - destination.second == 1)
				return MoveCode::Valid;
			if (_position.second == 6 && destination.second == 4 &&
				board.getPiece(Point(_position.first, 5)).getType() == PieceType::Empty)
				return MoveCode::Valid;
		}
		if (_color == Color::Black) {
			if (destination.second - _position.second == 1)
				return MoveCode::Valid;
			if (_position.second == 1 && destination.second == 3 &&
				board.getPiece(Point(_position.first, 2)).getType() == PieceType::Empty)
				return MoveCode::Valid;
		}
	}
	if (abs(_position.first - destination.first) == 1) {
		if (_color == Color::White) {
			if (_position.second - destination.second == 1)
				if (board.getPiece(destination).getColor() == Color::Black)
					return MoveCode::Valid;
				else if (board.getPiece(destination).getType() == PieceType::Empty &&
						 !board.getMoves().empty()) {
					const ChessMove* lastMove = board.getMoves().back();
					const ChessPiece& piece = board.getPiece(Point(destination.first, 3));
					if (lastMove->allowsEnPassant() && piece.getType() == PieceType::Pawn &&
						piece.getColor() == Color::Black)
						return MoveCode::Valid;
				}
		}
		if (_color == Color::Black) {
			if (destination.second - _position.second == 1)
				if (board.getPiece(destination).getColor() == Color::White)
					return MoveCode::Valid;
				else if (board.getPiece(destination).getType() == PieceType::Empty &&
						 !board.getMoves().empty()) {
					const ChessMove* lastMove = board.getMoves().back();
					const ChessPiece& piece = board.getPiece(Point(destination.first, 4));
					if (lastMove->allowsEnPassant() && piece.getType() == PieceType::Pawn &&
						piece.getColor() == Color::White)
						return MoveCode::Valid;
				}
		}
	}

	return MoveCode::InvalidMove;
}

void Pawn::getAvailableMoves(const Board& board, ChessMoves& moves) const
{
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
}