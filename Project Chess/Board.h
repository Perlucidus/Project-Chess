#ifndef _BOARD
#define _BOARD

#include "Definitions.h"
#include "ChessPiece.h"
#include "EmptyPiece.h"
#include "Point.h"
#include <map>

using namespace std;

class ChessPiece;

class Board {
public:
	Board();
	const ChessPiece& getPiece(const Point&) const;
	const ChessPiece& findPiece(Color, PieceType) const;
	void addPiece(const ChessPiece&);
	void deletePiece(const Point&);
	string toString() const;
private:
	map<Point, ChessPiece> _pieces;
};

#endif
