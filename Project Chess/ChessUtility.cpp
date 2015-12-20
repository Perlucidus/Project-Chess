#include "ChessUtility.h"
#include "ChessMove.h"

Point ChessUtility::parsePoint(const string& point)
{
	return Point(point[0] - 'a', '8' - point[1]);
}

MoveCode ChessUtility::makeMove(Board& board, Color color,
	const Point& source, const Point& destination)
{
	if (board.getPiece(source).getColor() != color)
		return MoveCode::InvalidSource;
	if (board.getPiece(destination).getColor() == color)
		return MoveCode::InvalidDestination;
	MoveCode code = board.getPiece(source).checkMove(board, destination);
	if (code != MoveCode::Valid)
		return code;
	Color oppositeColor = color == Color::Black ? Color::White : Color::Black;
	if (board.getPiece(destination).getType() == PieceType::Empty) {
		ChessMove move(board.getPiece(source), destination);
		move.doMove(board);
	}
	else {
		CaptureMove move(board.getPiece(source), board.getPiece(destination));
		move.doMove(board);
	}
	//if (isCheck(board, oppositeColor))
	//	return isMate(board, oppositeColor) ? MoveCode::CheckMate : MoveCode::Check;
	return MoveCode::Valid;
}

/*bool ChessUtility::isCheckMove(Board* board, Color color, Point source, Point destination)
{
	// TODO: Finish this
	return false;
}

bool ChessUtility::isCheck(Board* board, Color color)
{
	ChessPiece* king = board->findPiece(color, PieceType::King);
	if (!king)
		return false;
	for (size_t y = 0; y < BOARD_HEIGHT; y++)
		for (size_t x = 0; x < BOARD_WIDTH; x++)
			if (board->getPiece(x, y)->canMove(board, king->getPosition()))
				return true;
	return false;
}

bool ChessUtility::isMate(Board* board, Color color)
{
	ChessPiece* king = board->findPiece(color, PieceType::King);
	if (!king)
		return false;
	vector<Point> moves = king->getAvailableMoves(board);
	for (size_t i = 0; i < moves.size(); i++)
		if (!isCheckMove(board, color, king->getPosition(), moves[i]))
			return false;
	return true;
}*/
