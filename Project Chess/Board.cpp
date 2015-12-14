#include "Board.h"

Board::Board() {
	Initialize();
}

Board::~Board() {
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			delete _pieces[y][x];
}

ChessPiece* Board::getPiece(Point location) {
	return _pieces[location.y][location.x];
}

ChessPiece* Board::getPiece(int x, int y) {
	return _pieces[y][x];
}

ChessPiece* Board::findPiece(Color color, PieceType type) {
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (_pieces[y][x]
				&&_pieces[y][x]->getColor() == color
				&& _pieces[y][x]->getType() == type)
				return _pieces[y][x];
	return nullptr;
}

void Board::Initialize() {
	addPiece(new Rook(Color::Black, 0, 0));
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			addPiece(new EmptyPiece(Color::Transparent, x, y));
}

void Board::addPiece(ChessPiece* piece) {
	if (getPiece(piece->getLocation()))
		throw exception("Piece already exists at this location.");
	_pieces[piece->getLocation().getY()][piece->getLocation().getX()] = piece;
}
