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