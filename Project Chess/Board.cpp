#include "Board.h"
#include "EmptyPiece.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

Board::Board()
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			_pieces[y][x] = nullptr;
	Initialize();
}

Board::~Board()
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			delete _pieces[y][x];
}

ChessPiece* Board::getPiece(Point location)
{
	return _pieces[location.getY()][location.getX()];
}

ChessPiece* Board::getPiece(int x, int y)
{
	return _pieces[y][x];
}

ChessPiece* Board::findPiece(Color color, PieceType type)
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (_pieces[y][x]
				&&_pieces[y][x]->getColor() == color
				&& _pieces[y][x]->getType() == type)
				return _pieces[y][x];
	return nullptr;
}

void Board::move(Point source, Point destination)
{
	delete getPiece(destination);
	getPiece(source)->move(destination);
	_pieces[destination.getY()][destination.getX()] = getPiece(source);
	_pieces[source.getY()][source.getX()] = nullptr;
	addPiece(new EmptyPiece(source));
}

void Board::Initialize()
{
	addPiece(new Rook(Point(0, 0), Color::Black));
	addPiece(new Rook(Point(7, 0), Color::Black));
	addPiece(new Rook(Point(0, 7), Color::White));
	addPiece(new Rook(Point(7, 7), Color::White));
	addPiece(new King(Point(4, 7), Color::White));
	addPiece(new King(Point(3, 0), Color::Black));
	addPiece(new Knight(Point(1, 0), Color::Black));
	addPiece(new Knight(Point(6, 0), Color::Black));
	addPiece(new Knight(Point(1, 7), Color::White));
	addPiece(new Knight(Point(6, 7), Color::White));
	addPiece(new Bishop(Point(2, 0), Color::Black));
	addPiece(new Bishop(Point(5, 0), Color::Black));
	addPiece(new Bishop(Point(2, 7), Color::White));
	addPiece(new Bishop(Point(5, 7), Color::White));
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (!getPiece(Point(x, y)))
				addPiece(new EmptyPiece(Point(x, y)));
}

void Board::addPiece(ChessPiece* piece)
{
	if (getPiece(piece->getPosition()))
		throw exception("Piece already exists at this location.");
	_pieces[piece->getPosition().getY()][piece->getPosition().getX()] = piece;
}

string Board::toString()
{
	string str("");
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++) {
			ChessPiece* piece = getPiece(Point(x, y));
			if (piece->getColor() == Color::White)
				str.push_back((char)piece->getType() - ('a' - 'A'));
			else
				str.push_back((char)piece->getType());
		}
	return str;
}
