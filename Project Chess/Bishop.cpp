#include "Bishop.h"
#include <algorithm>

Bishop::Bishop(const Point& p, Color c) : ChessPiece(p, c, PieceType::Bishop){}

MoveCode Bishop::checkMove(const Board& board, const Point& destination) const
{
	MoveCode code = checkSanity(board, destination);
	if (code != MoveCode::Valid)
		return code;

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

void Bishop::getAvailableMoves(const Board& board, ChessMoves& moves) const
{
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