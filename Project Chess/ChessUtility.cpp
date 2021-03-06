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
	return isUnderAttack(board, color, king.getPosition());
}

bool ChessUtility::isUnderAttack(const Board& board, Color color, const Point& position) {
	for (ChessPieces::const_iterator it = board.getPieces().begin(); it != board.getPieces().end(); it++)
		if (it->second->getColor() != color && it->second->checkMove(board, position) == MoveCode::Valid)
			return true;
	return false;
}

bool ChessUtility::shortCastlingPossible(const Board& board, Color color) {
	for (ChessMoves::const_iterator it = board.getMoves().begin(); it != board.getMoves().end(); it++)
		if ((*it)->preventsShortCastling())
			return false;
	return true;
}

bool ChessUtility::longCastlingPossible(const Board& board, Color color) {
	for (ChessMoves::const_iterator it = board.getMoves().begin(); it != board.getMoves().end(); it++)
		if ((*it)->preventsLongCastling())
			return false;
	return true;
}

bool ChessUtility::isMate(Board& board, Color color) {
	const ChessPiece& king = board.findPiece(color, PieceType::King);
	if (king.getType() == PieceType::Empty)
		return false;
	ChessPieces pieces;
	pieces.clone(board.getPieces());
	for (ChessPieces::const_iterator it = pieces.begin(); it != pieces.end(); it++)
		if (it->second->getColor() == color) {
			ChessMoves moves;
			it->second->getAvailableMoves(board, moves);
			for (ChessMoves::const_iterator it2 = moves.begin(); it2 != moves.end(); it2++) {
				(*it2)->doMove(board);
				if (!isCheck(board, color)) {
					(*it2)->undoMove(board);
					return false;
				}
				(*it2)->undoMove(board);
			}
		}
	return true;
}
