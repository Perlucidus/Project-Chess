#include "ChessPiece.h"
#include "EmptyPiece.h"
#include "Rook.h"

ChessPiece::ChessPiece()
	: _position(Point(-1, -1)), _color(Color::Transparent), _type(PieceType::Empty) {}

ChessPiece::ChessPiece(const Point& position, Color color, PieceType type)
	: _position(position), _color(color), _type(type) {}

const Point& ChessPiece::getPosition() const
{
	return _position;
}

Color ChessPiece::getColor() const
{
	return _color;
}

PieceType ChessPiece::getType() const
{
	return _type;
}

void ChessPiece::move(const Point& destination)
{
	_position = destination;
}

MoveCode ChessPiece::checkMove(const Board& board, const Point& destination) const
{
	switch (_type) {
	case PieceType::Rook:
		((Rook*)this)->checkMove(board, destination);
		break;
	default:
		throw exception("Invalid piece type");
	}
}

MoveCode ChessPiece::checkSanity(const Board& board, const Point& destination) const
{
	if (!_position.inBounds(BOARD_WIDTH, BOARD_HEIGHT) ||
		!destination.inBounds(BOARD_WIDTH, BOARD_HEIGHT))
		return MoveCode::InvalidIndex;
	if (_position == destination)
		return MoveCode::MatchingPoints;
	return MoveCode::Valid;
}
