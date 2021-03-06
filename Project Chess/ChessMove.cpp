#include "Point.h"
#include "ChessMove.h"
#include "Board.h"
#include "Rook.h"
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
	while (!empty()) {
		const ChessMove* move = back();
		pop_back();
		delete move;
	}
}

void ChessMove::doMove(Board& board) const {
	ChessPiece* piece = _source->clone();
	board.deletePiece(_source->getPosition());
	piece->move(_destination);
	board.deletePiece(_destination);
	if (_source->getType() == PieceType::Pawn) {
		if (_destination.second == 0 || _destination.second == 7) {
			Color color = piece->getColor();
			delete piece;
			piece = new Queen(_destination, color);
		}
		else if (_source->getColor() == Color::White) {
			const ChessPiece& pawn = board.getPiece(Point(_destination.first, _destination.second + 1));
			if (pawn.getColor() == Color::Black)
				board.deletePiece(pawn.getPosition());
		} else if (_source->getColor() == Color::Black) {
			const ChessPiece& pawn = board.getPiece(Point(_destination.first, _destination.second - 1));
			if (pawn.getColor() == Color::White)
				board.deletePiece(pawn.getPosition());
		}
	}
	board.addPiece(*piece);
	delete piece;
}

void CastlingMove::doMove(Board& board) const {
	ChessMove::doMove(board);
	if (_destination.first > _source->getPosition().first)
		ChessMove(Rook(Point(7, _destination.second), _source->getColor()),
				  Point(5, _destination.second)).doMove(board);
	else
		ChessMove(Rook(Point(0, _destination.second), _source->getColor()),
				  Point(3, _destination.second)).doMove(board);
}

void ChessMove::undoMove(Board& board) const {
	board.deletePiece(_destination);
	board.addPiece(*_source);
}

bool ChessMove::allowsEnPassant() const {
	if (_source->getType() != PieceType::Pawn)
		return false;
	return abs(_destination.second - _source->getPosition().second) == 2;
}

bool ChessMove::preventsShortCastling() const {
	return _source->getType() == PieceType::King ||
		_source->getType() == PieceType::Rook && _source->getPosition().first == 7;
}

bool ChessMove::preventsLongCastling() const {
	return _source->getType() == PieceType::King ||
		_source->getType() == PieceType::Rook && _source->getPosition().first == 0;
}

void CaptureMove::undoMove(Board& board) const {
	ChessMove::undoMove(board);
	board.addPiece(*_target);
}

void CastlingMove::undoMove(Board& board) const {
	ChessMove::undoMove(board);
	if (_destination.first > _source->getPosition().first)
		ChessMove(Rook(Point(7, _destination.second), _source->getColor()),
				  Point(5, _destination.second)).undoMove(board);
	else
		ChessMove(Rook(Point(0, _destination.second), _source->getColor()),
				  Point(3, _destination.second)).undoMove(board);
}
