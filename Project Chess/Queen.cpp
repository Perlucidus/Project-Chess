#include "Queen.h"
#include <algorithm>

Queen::Queen(const Point& p, Color c) : ChessPiece(p, c, PieceType::Queen){}

MoveCode Queen::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;

	if (_position.first == destination.first)
	{
		for (int y = std::min(_position.second, destination.second) + 1;
			y < std::max(_position.second, destination.second) - 1; y++)
		{
			if (board.getPiece(Point(_position.first, y)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
		}
		return MoveCode::Valid;
	}
	if (_position.second == destination.second)
	{
		for (int x = std::min(_position.first, destination.first) + 1;
			x < std::max(_position.first, destination.first) - 1; x++)
		{
			if (board.getPiece(Point(x, _position.second)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
		}
		return MoveCode::Valid;
	}

	if (_position.first - destination.first == _position.second - destination.second)
	{
		int y = std::min(_position.second, destination.second) + 1;
		for (int x = std::min(_position.first, destination.first) + 1;
			x < std::max(_position.first, destination.first) && y < std::max(_position.second, destination.second); x++)
		{
			if (board.getPiece(Point(x, y)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
			y++;
		}
		return MoveCode::Valid;
	}
	if (_position.first - destination.first == -(_position.second - destination.second))
	{
		int y = std::max(_position.second, destination.second) - 1;
		for (int x = std::min(_position.first, destination.first) + 1;
			x < std::max(_position.first, destination.first) && y > std::min(_position.second, destination.second); x++)
		{
			if (board.getPiece(Point(x, y)).getType() != PieceType::Empty)
				return MoveCode::InvalidMove;
			y--;
		}
		return MoveCode::Valid;
	}
	return MoveCode::InvalidMove;
}

void Queen::getAvailableMoves(const Board& board, ChessMoves& moves) const
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

	int y = _position.second + 1;
	for (int x = _position.first + 1; x < BOARD_WIDTH && y < BOARD_HEIGHT; x++) {
		if (board.getPiece(Point(x, y)).getColor() == _color)
			break;
		if (board.getPiece(Point(x, y)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(x, y)));
		y++;
	}
	y = _position.second - 1;
	for (int x = _position.first - 1; x > 0 && y > 0; x--) {
		if (board.getPiece(Point(x, y)).getColor() == _color)
			break;
		if (board.getPiece(Point(x, y)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(x, y)));
		y--;
	}
	y = _position.second - 1;
	for (int x = _position.second; x < BOARD_WIDTH && y > 0; x++) {
		if (board.getPiece(Point(x, y)).getColor() == _color)
			break;
		if (board.getPiece(Point(x, y)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(x, y)));
		y++;
	}
	y = _position.second + 1;
	for (int x = _position.second; x > 0 && y < BOARD_HEIGHT; x--) {
		if (board.getPiece(Point(x, y)).getColor() == _color)
			break;
		if (board.getPiece(Point(x, y)).getType() != PieceType::Empty) {
			moves.push_back(new CaptureMove(*this, board.getPiece(Point(x, y))));
			break;
		}
		moves.push_back(new ChessMove(*this, Point(x, y)));
		y--;
	}
}