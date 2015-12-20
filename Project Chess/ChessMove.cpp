#include "ChessMove.h"
#include "Board.h"

ChessMove::ChessMove(const ChessPiece& source, const Point& destination)
	: _source(source), _destination(destination) {}

CaptureMove::CaptureMove(const ChessPiece& source, const ChessPiece& target)
	: ChessMove(source, target.getPosition()), _target(target) {}

void ChessMove::doMove(Board& board) const
{
	ChessPiece piece = _source;
	board.deletePiece(_source.getPosition());
	piece.move(_destination);
	board.deletePiece(_destination);
	board.addPiece(piece);
}

void ChessMove::undoMove(Board& board) const
{
	board.deletePiece(_destination);
	board.addPiece(_source);
}

void CaptureMove::undoMove(Board& board) const
{
	ChessMove::undoMove(board);
	board.addPiece(_target);
}
