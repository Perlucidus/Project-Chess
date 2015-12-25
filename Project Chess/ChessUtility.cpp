#include "ChessUtility.h"
#include "ChessMove.h"

Point ChessUtility::parsePoint(const string& point) {
	return Point(point[0] - 'a', '8' - point[1]);
}

MoveCode ChessUtility::makeMove(Board& board, Color color,
								const Point& source, const Point& destination) {
	if (board.getPiece(source).getColor() != color)
		return MoveCode::InvalidSource;
	MoveCode code = board.getPiece(source).checkMove(board, destination);
	if (code != MoveCode::Valid)
		return code;
	ChessMove* move;
	if (board.getPiece(destination).getType() == PieceType::Empty)
		if (board.getPiece(source).getType() == PieceType::King &&
			abs(source.first - destination.first) > 1)
			move = new CastlingMove(board.getPiece(source), destination);
		else
			move = new ChessMove(board.getPiece(source), destination);
	else
		move = new CaptureMove(board.getPiece(source), board.getPiece(destination));
	move->doMove(board);
	if (isCheck(board, color)) {
		move->undoMove(board);
		delete move;
		return MoveCode::InvalidCheck;
	}
	board.addMove(move);
	Color oppositeColor = color == Color::Black ? Color::White : Color::Black;
	if (isCheck(board, oppositeColor))
		return isMate(board, oppositeColor) ? MoveCode::CheckMate : MoveCode::Check;
	return MoveCode::Valid;
}

bool ChessUtility::isCheck(const Board& board, Color color) {
	const ChessPiece& king = board.findPiece(color, PieceType::King);
	if (king.getType() == PieceType::Empty)
		return false;
	for (ChessPieces::const_iterator it = board.getPieces().begin();
	it != board.getPieces().end(); it++)
		if (it->second->checkMove(board, king.getPosition()) == MoveCode::Valid)
			return true;
	return false;
}

bool ChessUtility::isMate(Board& board, Color color) {
	const ChessPiece& king = board.findPiece(color, PieceType::King);
	if (king.getType() == PieceType::Empty)
		return false;
	for (ChessPieces::const_iterator it = board.getPieces().begin(); it != board.getPieces().end(); it++)
		if (it->second->getColor() == color) {
			ChessMoves moves = it->second->getAvailableMoves(board);
			for (ChessMoves::const_iterator it = moves.begin(); it != moves.end(); it++) {
				(*it)->doMove(board);
				if (!isCheck(board, color))
					return false;
			}
		}
	return true;
}
