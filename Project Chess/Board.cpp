#include "Board.h"
#include "ChessMove.h"
#include "EmptyPiece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

EmptyPiece _emptyPiece;

Board::Board()
{
	addPiece(Rook(Point(0, 0), Color::Black));
	addPiece(Knight(Point(1, 0), Color::Black));
	addPiece(Bishop(Point(2, 0), Color::Black));
	addPiece(Queen(Point(3, 0), Color::Black));
	addPiece(King(Point(4, 0), Color::Black));
	addPiece(Bishop(Point(5, 0), Color::Black));
	addPiece(Knight(Point(6, 0), Color::Black));
	addPiece(Rook(Point(7, 0), Color::Black));

	addPiece(Rook(Point(0, 7), Color::White));
	addPiece(Knight(Point(1, 7), Color::White));
	addPiece(Bishop(Point(2, 7), Color::White));
	addPiece(Queen(Point(3, 7), Color::White));
	addPiece(King(Point(4, 7), Color::White));
	addPiece(Bishop(Point(5, 7), Color::White));
	addPiece(Knight(Point(6, 7), Color::White));
	addPiece(Rook(Point(7, 7), Color::White));

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		addPiece(Pawn(Point(i, 1), Color::Black));
		addPiece(Pawn(Point(i, 6), Color::White));
	}
}

Board::~Board() {}

const ChessPieces& Board::getPieces() const
{
	return _pieces;
}

const ChessPiece& Board::getPiece(const Point& position) const
{
	ChessPieces::const_iterator piece = _pieces.find(position);
	return piece != _pieces.end() ? *piece->second : _emptyPiece;
}

const ChessPiece& Board::findPiece(Color color, PieceType type) const
{
	for (ChessPieces::const_iterator it = _pieces.begin(); it != _pieces.end(); it++)
		if (it->second->getColor() == color && it->second->getType() == type)
			return *it->second;
	return _emptyPiece;
}

void Board::addPiece(const ChessPiece& piece)
{
	if (getPiece(piece.getPosition()).getType() != PieceType::Empty)
		throw exception("Piece already exists at this location.");
	if (_pieces.find(piece.getPosition()) != _pieces.end())
		delete _pieces[piece.getPosition()];
	_pieces[piece.getPosition()] = piece.clone();
}

void Board::deletePiece(const Point& position)
{
	if (_pieces.find(position) != _pieces.end())
	{
		delete _pieces[position];
		_pieces.erase(position);
	}
}

const ChessMoves& Board::getMoves() const
{
	return _moves;
}

void Board::addMove(const ChessMove* move)
{
	_moves.push_back(move);
}

string Board::toString() const
{
	string str("");
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			const ChessPiece& piece = getPiece(Point(x, y));
			if (piece.getColor() == Color::White)
				str.push_back((char)piece.getType() - ('a' - 'A'));
			else
				str.push_back((char)piece.getType());
		}
	return str;
}
