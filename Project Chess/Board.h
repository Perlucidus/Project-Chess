#include "Definitions.h"
#include "ChessPiece.h"
#include "Point.h"
#include <vector>
#include <exception>

using namespace std;

class Board {
private:
	ChessPiece* _pieces[BOARD_HEIGHT][BOARD_WIDTH];
	void Initialize();
	void addPiece(ChessPiece*) throw(exception);
public:
	Board();
	~Board();
	ChessPiece* getPiece(Point);
	ChessPiece* getPiece(int, int);
	ChessPiece* findPiece(Color, PieceType);
	Board* clone();
};
