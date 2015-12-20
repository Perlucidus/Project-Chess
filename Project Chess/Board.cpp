#include "Board.h"
#include "EmptyPiece.h"
#include "Rook.h"

EmptyPiece _emptyPiece;

Board::Board()
{
	addPiece(Rook(Point(0, 0), Color::Black));
	addPiece(Rook(Point(7, 0), Color::Black));
	addPiece(Rook(Point(0, 7), Color::White));
	addPiece(Rook(Point(7, 7), Color::White));
}

const ChessPiece& Board::getPiece(const Point& position) const
{
	std::map<Point, ChessPiece>::const_iterator piece = _pieces.find(position);
	return piece != _pieces.end() ? piece->second : _emptyPiece;
}

const ChessPiece& Board::findPiece(Color color, PieceType type) const
{
	for (std::map<Point, ChessPiece>::const_iterator it = _pieces.begin(); it != _pieces.end(); it++)
		if (it->second.getColor() == color && it->second.getType() == type)
			return it->second;
	return _emptyPiece;
}

void Board::addPiece(const ChessPiece& piece)
{
	if (getPiece(piece.getPosition()).getType() != PieceType::Empty)
		throw exception("Piece already exists at this location.");
	_pieces[piece.getPosition()] = piece;
}

void Board::deletePiece(const Point& position)
{
	_pieces.erase(position);
}

string Board::toString() const
{
	string str("");
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++) {
			const ChessPiece& piece = getPiece(Point(x, y));
			if (piece.getColor() == Color::White)
				str.push_back((char)piece.getType() - ('a' - 'A'));
			else
				str.push_back((char)piece.getType());
		}
	return str;
}
