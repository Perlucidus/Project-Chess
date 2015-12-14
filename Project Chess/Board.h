#ifndef _BOARD
#define _BOARD

#include "Definitions.h"
#include "ChessPiece.h"
#include "Point.h"
#include <vector>
#include <exception>

using namespace std;

class ChessPiece;

class Board {
public:
	Board();
	~Board();
	ChessPiece* getPiece(Point);
	ChessPiece* getPiece(int, int);
	ChessPiece* findPiece(Color, PieceType);
	void move(Point, Point);
	Board* clone();
	string toString();
private:
	ChessPiece* _pieces[BOARD_HEIGHT][BOARD_WIDTH];
	void Initialize();
	void addPiece(ChessPiece*);
};

#endif
