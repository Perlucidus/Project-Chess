#ifndef _CHESS_MOVE
#define _CHESS_MOVE

#include <vector>

class Board;
class Point;
class ChessPiece;

class ChessMove {
public:
	ChessMove(const ChessPiece&, const Point&);
	virtual ~ChessMove();
	virtual void doMove(Board&) const;
	virtual void undoMove(Board&) const;
	
	bool allowsEnPassant() const;
	bool preventsShortCastling() const;
	bool preventsLongCastling() const;
protected:
	ChessPiece* _source;
	Point _destination;
};

class CaptureMove : public ChessMove {
public:
	CaptureMove(const ChessPiece&, const ChessPiece&);
	virtual ~CaptureMove();
	void undoMove(Board&) const;
private:
	ChessPiece* _target;
};

class CastlingMove : public ChessMove {
public:
	CastlingMove(const ChessPiece&, const Point&);
	virtual ~CastlingMove();
	void doMove(Board&) const;
	void undoMove(Board&) const;
};

class ChessMoves : public std::vector<const ChessMove*> {
public:
	~ChessMoves();
};

#endif
