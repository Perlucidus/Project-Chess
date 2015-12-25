#include "Point.h"
#include "ChessMove.h"
#include "Board.h"
#include "Queen.h"

ChessMove::ChessMove(const ChessPiece& source, const Point& destination)
	: _source(source.clone()), _destination(destination) {}

ChessMove::~ChessMove() {
	delete _source;
}

CaptureMove::CaptureMove(const ChessPiece& source, const ChessPiece& target)
	: ChessMove(source, target.getPosition()), _target(target.clone()) {}

CaptureMove::~CaptureMove() {
	delete _target;
}

CastlingMove::CastlingMove(const ChessPiece& source, const Point& destination)
	: ChessMove(source, destination) {}

CastlingMove::~CastlingMove() {}

ChessMoves::~ChessMoves() {
	while (empty()) {
		delete back();
		pop_back();
	}
}

void ChessMove::doMove(Board& board) const {
	ChessPiece* piece = _source->clone();
	board.deletePiece(_source->getPosition());
	piece->move(_destination);
	board.deletePiece(_destination);
	if (_source->getType() == PieceType::Pawn &&
		(_destination.second == 0 || _destination.second == 7)) {
		delete piece;
		piece = new Queen(_destination, piece->getColor());
	}
	board.addPiece(*piece);
	delete piece;
}

void CastlingMove::doMove(Board& board) const {

}

void ChessMove::undoMove(Board& board) const {
	board.deletePiece(_destination);
	board.addPiece(*_source);
}

void CaptureMove::undoMove(Board& board) const {
	ChessMove::undoMove(board);
	board.addPiece(*_target);
}

void CastlingMove::undoMove(Board& board) const {

}
