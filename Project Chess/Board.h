#ifndef _BOARD
#define _BOARD

#include "Definitions.h"
#include "Point.h"
#include "ChessMove.h"
#include "ChessPiece.h"
#include "EmptyPiece.h"
#include <map>
#include <vector>

using namespace std;

class ChessPiece;

class Board {
public:
	Board();
	~Board();
	const ChessPieces& getPieces() const;
	const ChessPiece& getPiece(const Point&) const;
	const ChessPiece& findPiece(Color, PieceType) const;
	void addPiece(const ChessPiece&);
	void deletePiece(const Point&);
	const ChessMoves& getMoves() const;
	void addMove(const ChessMove*);
	string toString() const;
private:
	ChessPieces _pieces;
	ChessMoves _moves;
};

#endif
