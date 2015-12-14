#include "ChessUtility.h"

Point ChessUtility::parsePoint(string point) {
	return Point(point[0] - 'a', '8' - point[1]);
}

MoveCode ChessUtility::makeMove(Board* board, Color color, Point source, Point destination) {
	if (!source.inBounds(BOARD_WIDTH, BOARD_HEIGHT) ||
		!destination.inBounds(BOARD_WIDTH, BOARD_HEIGHT))
		return MoveCode::InvalidIndex;
	else if (source.equals(destination))
		return MoveCode::MatchingPoints;
	else if (board->getPiece(source)->getColor() != color)
		return MoveCode::InvalidSource;
	else if (board->getPiece(destination)->getColor() == color)
		return MoveCode::InvalidDestination;
	else if (!board->getPiece(source)->canMove(board, destination))
		return MoveCode::InvalidMove;
	//else if (isCheckMove(board, color, source, destination))
	//	return MoveCode::InvalidCheck;
	Color oppositeColor = color == Color::Black ? Color::White : Color::Black;
	board->move(source, destination);
	//if (isCheck(board, oppositeColor))
	//	return isMate(board, oppositeColor) ? MoveCode::CheckMate : MoveCode::Check;
	return MoveCode::Valid;
}

bool ChessUtility::isCheckMove(Board* board, Color color, Point source, Point destination) {
	// TODO: Finish this
	return false;
}

/*bool ChessUtility::isCheck(Board* board, Color color) {
	King* king = board->findPiece(color, PieceType::King);
	if (!king)
		return false;
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (board->getPiece(x, y)->canMove(board, king->getLocation()))
				return true;
	return false;
}*/

/*bool ChessUtility::isMate(Board* board, Color color) {
	King* king = board->findPiece(color, PieceType::King);
	if (!king)
		return false;
	vector<Point> moves = king->getAvailableMoves();
	for (int i = 0; i < moves.size(); i++)
		if (!isCheckMove(board, color, king->getLocation(), moves[i]))
			return false;
	return true;
}*/
