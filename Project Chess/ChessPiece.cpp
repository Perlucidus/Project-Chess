#include "ChessPiece.h"
#include "Board.h"

ChessPiece::ChessPiece()
	: _position(Point(-1, -1)), _color(Color::Transparent), _type(PieceType::Empty) {}

ChessPiece::ChessPiece(const Point& position, Color color, PieceType type)
	: _position(position), _color(color), _type(type) {}

const Point& ChessPiece::getPosition() const {
	return _position;
}

Color ChessPiece::getColor() const {
	return _color;
}

PieceType ChessPiece::getType() const {
	return _type;
}

void ChessPiece::setType(PieceType type) {
	_type = type;
}

void ChessPiece::move(const Point& destination) {
	_position = destination;
}

MoveCode ChessPiece::checkSanity(const Board& board, const Point& destination) const {
	if (_color == board.getPiece(destination).getColor())
		return MoveCode::InvalidDestination;
	if (!_position.inBounds(BOARD_WIDTH, BOARD_HEIGHT) ||
		!destination.inBounds(BOARD_WIDTH, BOARD_HEIGHT))
		return MoveCode::InvalidIndex;
	if (_position == destination)
		return MoveCode::MatchingPoints;
	return MoveCode::Valid;
}

ChessPieces::~ChessPieces() {
	for (ChessPieces::iterator it = begin(); it != end(); it++) {
		delete it->second;
		it->second = nullptr;
	}
	erase(begin(), end());
}

void ChessPieces::clone(const ChessPieces& pieces) {
	clear();
	for (ChessPieces::const_iterator it = pieces.begin(); it != pieces.end(); it++)
		operator[](it->first) = it->second->clone();
}
